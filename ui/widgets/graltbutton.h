#ifndef GRALTBUTTON_H
#define GRALTBUTTON_H

#include <QPushButton>
#include <QWidget>

class GrAltButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GrAltButton(const QString& name = "", QWidget* parent = nullptr);
};

#endif // GRALTBUTTON_H
