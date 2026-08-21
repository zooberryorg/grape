#ifndef GRWIDGET_H
#define GRWIDGET_H

#include <QWidget>

class QVBoxLayout;

class GrWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GrWidget(QWidget *parent = nullptr);
protected:
    QVBoxLayout *vLayout;
};

#endif // GRWIDGET_H
