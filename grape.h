#ifndef GRAPE_H
#define GRAPE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class grape;
}
QT_END_NAMESPACE

class grape : public QMainWindow
{
    Q_OBJECT

public:
    grape(QWidget *parent = nullptr);
    ~grape();

private:
    Ui::grape *ui;
};
#endif // GRAPE_H
