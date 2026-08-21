#ifndef GRWIDGET_H
#define GRWIDGET_H

#include <QWidget>

class GrWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GrWidget(QWidget *parent = nullptr);
    virtual QWidget* widget() = 0;
signals:
    QWidget* m_widget = nullptr;
};

#endif // GRWIDGET_H
