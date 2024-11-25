#include "nordvpn_qt.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDebug>
#include <QProcess> // this contains SIGNALS errorOccurred, finshed, started, readyReadStandardOutput

NordVPNGUI::NordVPNGUI(QWidget *parent)
    : QMainWindow(parent)
    , isPopulatingCountries(false)
    , isPopulatingCities(false)
{
    setupUI();
    
    // Initialize process
    process = new QProcess(this);
//    connect(process, &QProcess::finished, this, &NordVPNGUI::onProcessFinished);
    //bkt!! -- I do NOT understand why the following horrible type-cast... got it form stackOverflow
    connect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &NordVPNGUI::onProcessFinished);
    connect(process, &QProcess::errorOccurred, this, &NordVPNGUI::onProcessError);
    connect(process, &QProcess::readyReadStandardOutput, this, &NordVPNGUI::onProcessOutput);
    connect(process, &QProcess::readyReadStandardError, this, &NordVPNGUI::onProcessErrorOutput);
    
    // Initialize connect-status time
    connectTimer = new QTimer(this);
    connectTimer->setSingleShot(true);
    connect(connectTimer, &QTimer::timeout, this, &NordVPNGUI::onConnectStatusCheck);


    // Initialize disconnect timer
    disconnectTimer = new QTimer(this);
    disconnectTimer->setSingleShot(true);
    connect(disconnectTimer, &QTimer::timeout, this, &NordVPNGUI::onDisconnectStatusCheck);
    
    // Initialize periodic STATUS check timer
    periodicStatusTimer = new QTimer(this);
    connect(periodicStatusTimer, &QTimer::timeout, this, &NordVPNGUI::onPeriodicStatusCheck);


    // Initialize settings
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/.nordvpn_gui.ini";
    settings = new QSettings(configPath, QSettings::IniFormat);
    
    verifyNordVPNExists();
    loadSettings();
    populateCountries();
}

NordVPNGUI::~NordVPNGUI()
{
    delete settings;
}

void NordVPNGUI::setupUI()
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    // Dropdowns
    QHBoxLayout *dropdownLayout = new QHBoxLayout();
    
    countryCombo = new QComboBox();
    cityCombo = new QComboBox();
    
    dropdownLayout->addWidget(new QLabel("Country:"));
    dropdownLayout->addWidget(countryCombo);
    dropdownLayout->addWidget(new QLabel("City:"));
    dropdownLayout->addWidget(cityCombo);
    
    connect(countryCombo, &QComboBox::currentTextChanged,
            this, &NordVPNGUI::onCountrySelected);
    
    // Buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    connectButton = new QPushButton("Connect");
    disconnectButton = new QPushButton("Disconnect");
    statusButton = new QPushButton("Status");
    versionButton = new QPushButton("Version");
    
    connect(connectButton, &QPushButton::clicked, this, &NordVPNGUI::onConnectClicked);
    connect(disconnectButton, &QPushButton::clicked, this, &NordVPNGUI::onDisconnectClicked);
    connect(statusButton, &QPushButton::clicked, this, &NordVPNGUI::onStatusClicked);
    connect(versionButton, &QPushButton::clicked, this, &NordVPNGUI::onVersionClicked);
    
    buttonLayout->addWidget(connectButton);
    buttonLayout->addWidget(disconnectButton);
    buttonLayout->addWidget(statusButton);
    buttonLayout->addWidget(versionButton);
    
    // Output text area
    outputText = new QTextEdit();
    outputText->setReadOnly(true);
    
    mainLayout->addLayout(dropdownLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(outputText);
    
    resize(640, 480);
}

void NordVPNGUI::verifyNordVPNExists()
{
    QProcess which;
    which.start("which", QStringList() << "nordvpn");
    which.waitForFinished();
    
    if (which.exitCode() != 0) {
        QMessageBox::critical(this, "Error", "nordvpn command not found!");
        QTimer::singleShot(0, this, &QMainWindow::close);
    }
}

void NordVPNGUI::loadSettings()
{
    savedCountry = settings->value("country").toString();
    savedCity = settings->value("city").toString();
}

void NordVPNGUI::saveSettings()
{
    settings->setValue("country", countryCombo->currentText());
    settings->setValue("city", cityCombo->currentText());
    settings->sync();
}

void NordVPNGUI::populateCountries()
{
    isPopulatingCountries = true;
    currentOutput.clear();
    runCommand(QStringList() << "countries");
}

void NordVPNGUI::populateCities(const QString &country)
{
    if (country.isEmpty()) return;
    
    isPopulatingCities = true;
    pendingCityPopulation = country;
    currentOutput.clear();
    runCommand(QStringList() << "cities" << country);
}

void NordVPNGUI::runCommand(const QStringList &arguments, bool appendOutput)
{
    if (process->state() != QProcess::NotRunning) {
        process->kill();
        process->waitForFinished();
    }
    
    if (!appendOutput) {
        currentOutput.clear();
    }
    
    process->start("nordvpn", arguments);
    
    // Set timeout
    QTimer::singleShot(15000, this, [this]() {
        if (process->state() != QProcess::NotRunning) {
            process->kill();
            displayError("Command timed out after 15 seconds");
        }
    });
}

void NordVPNGUI::onCountrySelected(const QString &country)
{
    if (!country.isEmpty() && !isPopulatingCountries) {
        populateCities(country);
    }
}

void NordVPNGUI::onConnectClicked()
{
    QString country = countryCombo->currentText();
    QString city = cityCombo->currentText();
    
    if (!country.isEmpty() && !city.isEmpty()) {
        saveSettings();
        runCommand(QStringList() << "connect" << country << city);
        connectTimer->start(6000); // 6 second delay
    }
}

void NordVPNGUI::onDisconnectClicked()
{
    runCommand(QStringList() << "disconnect");
    disconnectTimer->start(2000); // 2 second delay
}

void NordVPNGUI::onConnectStatusCheck()
{
    runCommand(QStringList() << "status", true);

    if (periodicStatusTimer->isActive())
        periodicStatusTimer->stop();

    periodicStatusTimer->start(30000); // 30-seconds

}

void NordVPNGUI::onDisconnectStatusCheck()
{
    runCommand(QStringList() << "status", true);

    if (periodicStatusTimer->isActive())
        periodicStatusTimer->stop();
}

void NordVPNGUI::onPeriodicStatusCheck()
{
    runCommand(QStringList() << "status");
}


void NordVPNGUI::onStatusClicked()
{
    runCommand(QStringList() << "status");
}

void NordVPNGUI::onVersionClicked()
{
    runCommand(QStringList() << "version");
}

void NordVPNGUI::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if (exitCode != 0 || exitStatus != QProcess::NormalExit) {
        displayError("Command failed");
        return;
    }

    if (isPopulatingCountries) {
        lastKnownCountries = currentOutput.join(" ").split(QRegExp("\\s+"), Qt::SkipEmptyParts);
        countryCombo->clear();
        countryCombo->addItems(lastKnownCountries);
        
        if (lastKnownCountries.contains(savedCountry)) {
            countryCombo->setCurrentText(savedCountry);
        } else if (!lastKnownCountries.isEmpty()) {
            countryCombo->setCurrentIndex(0);
        }
        
        isPopulatingCountries = false;
        onCountrySelected(savedCountry); //bkt!!
        
    } else if (isPopulatingCities) {
        QStringList cities = currentOutput.join(" ").split(QRegExp("\\s+"), Qt::SkipEmptyParts);
        lastKnownCities[pendingCityPopulation] = cities;
        
        cityCombo->clear();
        cityCombo->addItems(cities);
        
        if (pendingCityPopulation == savedCountry && cities.contains(savedCity)) {
            cityCombo->setCurrentText(savedCity);
        } else if (!cities.isEmpty()) {
            cityCombo->setCurrentIndex(0);
        }
        
        isPopulatingCities = false;
        pendingCityPopulation.clear();
        
    } else {
        outputText->setPlainText(currentOutput.join("\n"));
    }
}

void NordVPNGUI::onProcessError(QProcess::ProcessError error)
{
    QString errorMessage;
    switch (error) {
        case QProcess::FailedToStart:
            errorMessage = "Failed to start nordvpn";
            break;
        case QProcess::Crashed:
            errorMessage = "nordvpn process crashed";
            break;
        case QProcess::Timedout:
            errorMessage = "Command timed out";
            break;
        case QProcess::WriteError:
            errorMessage = "Write error";
            break;
        case QProcess::ReadError:
            errorMessage = "Read error";
            break;
        default:
            errorMessage = "Unknown error";
    }
    displayError(errorMessage);
}

void NordVPNGUI::onProcessOutput()
{
    QString output = QString::fromUtf8(process->readAllStandardOutput());
    currentOutput.append(output.split('\n', Qt::SkipEmptyParts));
}

void NordVPNGUI::onProcessErrorOutput()
{
    QString error = QString::fromUtf8(process->readAllStandardError());
    displayError(error);
}

void NordVPNGUI::displayError(const QString &message)
{
    QMessageBox::critical(this, "Error", message);
}
