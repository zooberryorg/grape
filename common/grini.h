#ifndef GRINI_H
#define GRINI_H

// layer over simple ini that returns Qt friendly objects

#include <QStringList>
#include <QHash>
#include "SimpleIni.h"
#include "grshared.h"

using Value = GrShared::Value;

class GrINI
{
public:
    struct SectionTemplate {
        QString sectionName;
        QHash<QString, GrShared::Value> properties;
    };
    static QString buildSectionName(const QString& prefix, const QString& sectionName);
    static QHash<QString, QString> getKeyValuesInSection(const CSimpleIniA& ini, QString section);
    static void assignNewValuesToKeys(GrShared::Key& target, const QHash<QString, QString>& input);
    static QStringList getFlagsInSection(const QString& path, const QString& section);
    static bool doesSectionExist(const CSimpleIniA&, const QString&);
    static bool doesKeyInSectionExist(const CSimpleIniA&, const QString&, const QString&);
    static void loadConfig(const CSimpleIniA&, QHash<QString, GrShared::Section> config);
    static QVariant stringToBool(const QString& b);
    static void registerSubtypes(QHash<QString, GrShared::Section>& target, const SectionTemplate& tmpl, const GrShared::SubtypeList& subtypes);
};

#endif // GRINI_H
