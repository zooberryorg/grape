#ifndef GRCHECKBOX_H
#define GRCHECKBOX_H

#include <QCheckBox>
#include "grwidget.h"

class QLabel;
class QCheckBox;

class GrCheckBox : public GrWidget
{
    Q_OBJECT
public:
    explicit GrCheckBox(QWidget *parent = nullptr, const QString& label = "", const QString& caption = "");
    QWidget* widget() override { return checkbox; };

signals:

private:
    QCheckBox *checkbox;
    QLabel* label;
};

#endif // GRCHECKBOX_H
