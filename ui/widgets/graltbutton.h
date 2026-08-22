#ifndef GRALTBUTTON_H
#define GRALTBUTTON_H

#include <QPushButton>
#include <QWidget>

class QEnterEvent;
class QEnter;

class GrAltButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GrAltButton(const QString& name = "", QWidget* parent = nullptr);
    void setNormalIcon(const QIcon& icon);
    void setHoverIcon(const QIcon& icon);

protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;

private:
    QIcon m_normalIcon;
    QIcon m_hoverIcon;
    QPalette normalPal;
    QPalette hoverPal;
};


#endif // GRALTBUTTON_H
