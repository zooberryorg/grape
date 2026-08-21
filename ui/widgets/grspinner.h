#ifndef GRSPINNER_H
#define GRSPINNER_H

#include "grwidget.h"

class QSpinBox;

class GrSpinner : public GrWidget
{
    Q_OBJECT
public:
    explicit GrSpinner(QWidget *parent = nullptr, const QString& label = "", const QString& caption = "");
    QSpinBox* widget() { return spinbox; };

private:
    QSpinBox *spinbox;
};

#endif // GRSPINNER_H
