#ifndef NORDVPN_QT_H
#define NORDVPN_QT_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include <QProcess>
#include <QTimer>
#include <QSettings>

class NordVPNGUI : public QMainWindow {
    Q_OBJECT

public:
    NordVPNGUI(QWidget *parent = nullptr);
    ~NordVPNGUI();

private slots:
    void onCountrySelected(const QString &country);
    void onConnectClicked();
    void onDisconnectClicked();
    void onStatusClicked();
    void onVersionClicked();
    void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onProcessError(QProcess::ProcessError error);
    void onProcessOutput();
    void onProcessErrorOutput();
    void onConnectStatusCheck();
    void onDisconnectStatusCheck();
    void onPeriodicStatusCheck();


private:
    void setupUI();
    void verifyNordVPNExists();
    void loadSettings();
    void saveSettings();
    void populateCountries();
    void populateCities(const QString &country);
    void runCommand(const QStringList &arguments, bool appendOutput = false);
    void displayError(const QString &message);

    QComboBox *countryCombo;
    QComboBox *cityCombo;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QPushButton *statusButton;
    QPushButton *versionButton;
    QTextEdit *outputText;
    
    QProcess *process;
    QTimer *connectTimer;
    QTimer *disconnectTimer;
    QTimer *periodicStatusTimer;
    QSettings *settings;
    
    QString savedCountry;
    QString savedCity;
    QStringList lastKnownCountries;
    QMap<QString, QStringList> lastKnownCities;
    
    bool isPopulatingCountries;
    bool isPopulatingCities;
    QString pendingCityPopulation;
    QStringList currentOutput;
};

#endif // NORDVPN_QT_H
