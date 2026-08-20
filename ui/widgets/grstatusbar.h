#ifndef GRSTATUSBAR_H
#define GRSTATUSBAR_H

#include <QStatusBar>
#include <QWidget>

class QLabel;

class GrStatusBar : public QStatusBar
{
    Q_OBJECT
public:
    GrStatusBar(QWidget *parent);
private:
    QLabel* version;
};

#endif // GRSTATUSBAR_H
