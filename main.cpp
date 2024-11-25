#include "nordvpn_qt.h"
#include <QApplication>
#include <QStyleFactory>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("NordVPN_QT_GUI");
    app.setOrganizationName("NordVPN");


// #define TRY_DARK_MODE1
#define TRY_DARK_MODE2
#ifdef TRY_DARK_MODE1

    qApp->setStyle(QStyleFactory::create("Fusion"));

    // attempt DARK palette from https://www.medo64.com/2020/08/dark-mode-for-qt-application/
    QPalette newPalette;
    newPalette.setColor(QPalette::Window,          QColor( 37,  37,  37));
    newPalette.setColor(QPalette::WindowText,      QColor(212, 212, 212));
    newPalette.setColor(QPalette::Base,            QColor( 60,  60,  60));
    newPalette.setColor(QPalette::AlternateBase,   QColor( 45,  45,  45));
    newPalette.setColor(QPalette::PlaceholderText, QColor(127, 127, 127));
    newPalette.setColor(QPalette::Text,            QColor(212, 212, 212));
    newPalette.setColor(QPalette::Button,          QColor( 45,  45,  45));
    newPalette.setColor(QPalette::ButtonText,      QColor(212, 212, 212));
    newPalette.setColor(QPalette::BrightText,      QColor(240, 240, 240));
    newPalette.setColor(QPalette::Highlight,       QColor( 38,  79, 120));
    newPalette.setColor(QPalette::HighlightedText, QColor(240, 240, 240));

    newPalette.setColor(QPalette::Light,           QColor( 60,  60,  60));
    newPalette.setColor(QPalette::Midlight,        QColor( 52,  52,  52));
    newPalette.setColor(QPalette::Dark,            QColor( 30,  30,  30) );
    newPalette.setColor(QPalette::Mid,             QColor( 37,  37,  37));
    newPalette.setColor(QPalette::Shadow,          QColor( 0,    0,   0));

    newPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));

    qApp->setPalette(newPalette);
#endif /* TRY_DARK_MODE1 */

#ifdef TRY_DARK_MODE2
    // from https://stackoverflow.com/questions/15035767/is-the-qt-5-dark-fusion-theme-available-for-windows
    // set style
    qApp->setStyle(QStyleFactory::create("Fusion"));

    // modify palette to dark
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window,QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText,Qt::white);
    darkPalette.setColor(QPalette::Disabled,QPalette::WindowText,QColor(127,127,127));
    darkPalette.setColor(QPalette::Base,QColor(42,42,42));
    darkPalette.setColor(QPalette::AlternateBase,QColor(66,66,66));
    darkPalette.setColor(QPalette::ToolTipBase,Qt::white);
    darkPalette.setColor(QPalette::ToolTipText,Qt::white);
    darkPalette.setColor(QPalette::Text,Qt::white);
    darkPalette.setColor(QPalette::Disabled,QPalette::Text,QColor(127,127,127));
    darkPalette.setColor(QPalette::Dark,QColor(35,35,35));
    darkPalette.setColor(QPalette::Shadow,QColor(20,20,20));
    darkPalette.setColor(QPalette::Button,QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText,Qt::white);
    darkPalette.setColor(QPalette::Disabled,QPalette::ButtonText,QColor(127,127,127));
    darkPalette.setColor(QPalette::BrightText,Qt::red);
    darkPalette.setColor(QPalette::Link,QColor(42,130,218));
    darkPalette.setColor(QPalette::Highlight,QColor(42,130,218));
    darkPalette.setColor(QPalette::Disabled,QPalette::Highlight,QColor(80,80,80));
    darkPalette.setColor(QPalette::HighlightedText,Qt::white);
    darkPalette.setColor(QPalette::Disabled,QPalette::HighlightedText,QColor(127,127,127));

    qApp->setPalette(darkPalette);
#endif /* TRY_DARK_MODE2 */


    NordVPNGUI window;
    window.show();
    
    return app.exec();
}
