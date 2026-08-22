#ifndef GRLINEEDIT_H
#define GRLINEEDIT_H

#include <QWidget>
#include "grwidget.h"
#include <QLineEdit>

class QLineEdit;

class GrLineEdit : public GrWidget
{
    Q_OBJECT
public:
    explicit GrLineEdit(QWidget *parent = nullptr, const QString& label = "", const QString& caption = "");
    QLineEdit* widget() { return lineEdit; };

private:
    QLineEdit *lineEdit;
};

#endif // GRLINEEDIT_H
