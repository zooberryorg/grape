#ifndef GRSPINNER_H
#define GRSPINNER_H

#include <QWidget>

class QSpinBox;

class GrSpinner : public QWidget
{
    Q_OBJECT
public:
    explicit GrSpinner(QWidget *parent = nullptr, const QString& label = "", const QString& caption = "");
    QSpinBox* widget() { return spinbox; };

signals:

private:
    QSpinBox *spinbox;
};

#endif // GRSPINNER_H
