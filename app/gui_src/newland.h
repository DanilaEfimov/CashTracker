#ifndef NEWLAND_H
#define NEWLAND_H

#include <QWidget>

namespace Ui {
class newland;
}

class newland : public QWidget
{
    Q_OBJECT

public:
    explicit newland(QWidget *parent = nullptr);
    ~newland();

private:
    Ui::newland *ui;
};

#endif // NEWLAND_H
