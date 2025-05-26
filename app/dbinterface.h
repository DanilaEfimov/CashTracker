#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <QWidget>

namespace Ui {
class dbinterface;
}

class dbinterface : public QWidget
{
    Q_OBJECT

public:
    explicit dbinterface(QWidget *parent = nullptr);
    ~dbinterface();

private:
    Ui::dbinterface *ui;
};

#endif // DBINTERFACE_H
