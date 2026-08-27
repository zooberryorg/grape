#include "grini.h"
#include <QFile>
#include <QTextStream>
#include <QVariant>

QString GrINI::buildSectionName(const QString &prefix, const QString &sectionName)
{
    if ( prefix.isEmpty() ) {
        return sectionName;
    } else {
        return prefix + '/' + sectionName;
    }
}

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

bool GrINI::doesSectionExist(const CSimpleIniA& ini, const QString& inputSection)
{
    CSimpleIniA::TNamesDepend sections;
    ini.GetAllSections(sections);

    for ( const auto& section : sections ) {
        QString s_section = QString(section.pItem);
        if ( s_section == inputSection ) {
            return true;
        }
    }

    return false;
}

bool GrINI::doesKeyInSectionExist(const CSimpleIniA& ini, const QString& section, const QString& key)
{
    CSimpleIniA::TNamesDepend memberKeys;
    ini.GetAllKeys(section.toStdString().c_str(), memberKeys);
    QHash<QString, QString> pairs;

    for ( const auto& k : memberKeys ) {
        if ( QString(k.pItem) == key ) {
            return true;
        }
    }

    return false;
}

void GrINI::assignNewValuesToKeys(GrShared::Key& target, const QHash<QString, QString>& input)
{
    if (target.isEmpty())
        return;

    for (auto it = input.constBegin(); it != input.constEnd(); ++it) {
        if (target.contains(it.key())) {
            target[it.key()].v = it.value();
        }
    }
}

void GrINI::loadConfig(const CSimpleIniA& ini, QHash<QString, GrShared::Section> config)
{
    for (const auto& subtype : config )
    {
        QString subTypeName = subtype.begin().key();
        for (const auto& section : subtype) {
            QString sectionName = section.begin().key();
            GrINI::assignNewValuesToKeys(
                config,
                GrINI::getKeyValuesInSection(ini, sectionName)
            );
        }
    }
}

QVariant GrINI::stringToBool(const QString &b)
{
    if ( b == "0" ) {
        return false;
    }
    else if ( b == "1" ) {
        return true;
    }

    return QVariant();
}

// takes all pre-registered INI sections and adds any subtypes that exist
void GrINI::registerSubtypes(QHash<QString, GrShared::Section>& target, const SectionTemplate& tmpl, const GrShared::SubtypeList& subtypes)
{
    for (const auto& sub : subtypes) {

        const QString sectionName = buildSectionName(sub.prefix, tmpl.sectionName);

        for (auto it = tmpl.properties.constBegin(); it != tmpl.properties.constEnd(); ++it) {
            target[sub.prefix][sectionName][it.key()] = it.value();
        }
    }
}
