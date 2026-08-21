#ifndef GRLANGTABLEBROWSER_H
#define GRLANGTABLEBROWSER_H

#include <QWidget>

class GrLangTableBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit GrLangTableBrowser(QWidget *parent = nullptr, const QString& path = "");

signals:

};

#endif // GRLANGTABLEBROWSER_H
