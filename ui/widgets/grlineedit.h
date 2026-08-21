#ifndef GRLINEEDIT_H
#define GRLINEEDIT_H

#include <QWidget>
#include "grwidget.h"

class QLineEdit;

class GrLineEdit : public GrWidget
{
    Q_OBJECT
public:
    explicit GrLineEdit(QWidget *parent = nullptr, const QString& caption = "", const QString& label = "");

signals:

private:
    QLineEdit *lineEdit;
};

#endif // GRLINEEDIT_H
