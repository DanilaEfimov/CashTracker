#ifndef NOTEINTERFACE_H
#define NOTEINTERFACE_H

#include <QWidget>

namespace Ui {
class noteinterface;
}

class noteinterface : public QWidget
{
    Q_OBJECT

public:
    explicit noteinterface(QWidget *parent = nullptr);
    ~noteinterface();

private:
    Ui::noteinterface *ui;
};

#endif // NOTEINTERFACE_H
