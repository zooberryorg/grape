#ifndef GRCHECKBOX_H
#define GRCHECKBOX_H

#include <QWidget>

class QLabel;
class QCheckBox;

class GrCheckbox : public QWidget
{
    Q_OBJECT
public:
    explicit GrCheckbox(QWidget *parent = nullptr, const QString& label = "", const QString& caption = "");

signals:

private:
    QCheckBox *checkbox;
    QLabel* label;
};

#endif // GRCHECKBOX_H
