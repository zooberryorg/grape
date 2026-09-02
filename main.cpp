#include "apew.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QtWidgets>

#include <QtLogging>
#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QFontDatabase>

void msgHandler( QtMsgType type, const QMessageLogContext &context, const QString &msg )
{
    const char symbols[] = { 'I', 'E', '!', 'X' };
    QString output = QString("[%1] %2").arg( symbols[type] ).arg( msg );
    std::cerr << output.toStdString() << std::endl;
    if( type == QtFatalMsg ) abort();
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler( msgHandler );
    QApplication a(argc, argv);

    // setup qss
    QFile style(":/styles/ape.qss");
    style.open(QFile::ReadOnly);
    a.setStyleSheet(QLatin1String(style.readAll()));

    // install fonts
    QFontDatabase::addApplicationFont(":/fonts/Roboto-Light.ttf");
    QFontDatabase::addApplicationFont(":/fonts/Roboto-Regular.ttf");
    QFontDatabase::addApplicationFont(":/fonts/Roboto-Medium.ttf");
    QFontDatabase::addApplicationFont(":/fonts/Roboto-SemiBold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/Roboto-Bold.ttf");

    a.setFont(QFont("Roboto", 11));

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "grape_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    ApeW w;
    w.show();
    return a.exec();
}
