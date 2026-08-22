#include "grpe.h"

#include <LIEF/LIEF.hpp>
#include <QDebug>
#include <QFileInfo>

namespace GrPE {

    QVector<GrPE::Entry> getStringTables(const QString &path)
    {

        QVector<GrPE::Entry> result;
        QFileInfo* file = new QFileInfo(path);

        std::unique_ptr<LIEF::PE::Binary> binary = LIEF::PE::Parser::parse(path.toStdString());
        if (!binary) {
            qDebug() << "Failed to parse: " << path << "\n";
            return result;
        }

        if (!binary->has_resources()) {
            qDebug() << "No resources in: " << path << "\n";
            return result;
        }

        auto res = binary->resources_manager();
        if (!res) {
            qDebug() << "Failed to get resources manager for: " << path << "\n";
            return result;
        }
        LIEF::PE::ResourcesManager& mgr = res.value();

        if (!mgr.has_string_table()) {
            qDebug() << "No RT_STRING table in: " << path << "\n";
            return result;
        }

        for (const auto& entry : mgr.string_table()) {
            if (!entry.is_defined())
                continue;
            result.append(GrPE::Entry{ entry.id, QString(entry.string), file->fileName() });
        }

        return result;

    }

}
