#include "grape.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QtWidgets>

int main(int argc, char *argv[])
{
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
    grape w;
    w.resize(320, 240);
    w.show();
    w.setWindowTitle(
        QApplication::translate("main_w_title", "GrAPE")
        );

    QPushButton *button = new QPushButton(
        QApplication::translate("main_w_button", "Press Me"), &w
        );
    button->show();
    return a.exec();
}
