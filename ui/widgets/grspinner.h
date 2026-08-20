#ifndef GRSPINNER_H
#define GRSPINNER_H

#include <QWidget>

class QSpinBox;

class GrSpinner : public QWidget
{
    Q_OBJECT
public:
    explicit GrSpinner(QWidget *parent, const QString& label, const QString& caption);

signals:

private:
    QSpinBox *spinbox;
};

#endif // GRSPINNER_H
