#ifndef GRCHECKBOX_H
#define GRCHECKBOX_H

#include <QWidget>

class QLabel;
class QCheckBox;

class GrCheckBox : public QWidget
{
    Q_OBJECT
public:
    explicit GrCheckBox(QWidget *parent = nullptr, const QString& label = "", const QString& caption = "");
    QCheckBox* widget() { return checkbox; };

signals:

private:
    QCheckBox *checkbox;
    QLabel* label;
};

#endif // GRCHECKBOX_H
