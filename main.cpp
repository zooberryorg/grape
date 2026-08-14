#include "grapew.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QtWidgets>

#include <QtLogging>
#include <QCoreApplication>
#include <QDebug>
#include <iostream>

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

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "grape_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    GrapeW w;
    w.show();
    return a.exec();
}
