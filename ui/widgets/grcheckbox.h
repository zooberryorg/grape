#ifndef GRCHECKBOX_H
#define GRCHECKBOX_H

#include <QWidget>
#include <QCheckBox>

class GrCheckbox : public QCheckBox
{
    Q_OBJECT
public:
    explicit GrCheckbox(QWidget *parent = nullptr, const QString& label = "");

signals:

private:
    QCheckBox *checkbox;
};

#endif // GRCHECKBOX_H
