#ifndef GRIDSELECTOR_H
#define GRIDSELECTOR_H

#include <QWidget>

class QVBoxLayout;
class QHBoxLayout;

class GrIdSelector : public QWidget
{
    Q_OBJECT
public:
    explicit GrIdSelector(QWidget *parent = nullptr);
private:
    QVBoxLayout* layout;
    QHBoxLayout* buttonLayout;
signals:

};

#endif // GRIDSELECTOR_H
