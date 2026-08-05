#ifndef GRFOREST_H
#define GRFOREST_H

#include "grtreenode.h"

namespace GrForest {
    GrTreeNode* load();
    GrTreeNode* load(const QString& file);
};

#endif // GRFOREST_H
