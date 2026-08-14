#include "grini.h"
#include <QFile>
#include <QTextStream>

QHash<QString, QString> GrINI::getKeyValuesInSection(const CSimpleIniA& ini, QString section)
{
    CSimpleIniA::TNamesDepend memberKeys;
    ini.GetAllKeys(section.toStdString().c_str(), memberKeys);
    QHash<QString, QString> pairs;

    for ( const auto& key : memberKeys ) {
        QString value = QString(ini.GetValue(section.toStdString().c_str(), key.pItem));
        pairs.insert(QString(key.pItem), value);
    }

    return pairs;
}

void GrINI::assignNewValuesToKeys(QHash<QString, QHash<QString, QString>>& target, const QHash<QString, QString>& input) {
    QString section = target.begin().key();
    for (const auto& key : input.keys()) {
        if ( target[section].contains(key) ) {
            target[section][key] = input.value(key);
        }
    }
}

QStringList GrINI::getFlagsInSection(const QString& path, const QString& section)
{
    QStringList flags;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return flags;

    QTextStream in(&file);
    bool inSection = false;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty())
            continue;

        if (line.startsWith('[')) {
            inSection = (line.compare("[" + section + "]", Qt::CaseInsensitive) == 0);
            continue;
        }

        if (inSection) {
            flags.append(line.toLower());
        }
    }

    return flags;
}
