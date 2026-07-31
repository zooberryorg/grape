#ifndef GRAPE_H
#define GRAPE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class GrapeW;
}
QT_END_NAMESPACE

class GrapeW : public QMainWindow
{
    Q_OBJECT

public:
    GrapeW(QWidget *parent = nullptr);
    ~GrapeW();

private:
    Ui::GrapeW *ui;
};
#endif // GRAPE_H
