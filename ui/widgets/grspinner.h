#ifndef GRSPINNER_H
#define GRSPINNER_H

#include <QSpinBox>
#include "grwidget.h"

class GrSpinner : public GrWidget
{
    Q_OBJECT
public:
    explicit GrSpinner(QWidget *parent = nullptr, const QString& label = "", const QString& caption = "");
    QWidget* widget() override { return spinbox; };

private:
    QSpinBox *spinbox;
};

#endif // GRSPINNER_H
