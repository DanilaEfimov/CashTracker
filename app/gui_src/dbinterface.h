#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include "general.h"

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

    static int logErr(const QString& what, const QString& path = LOG_FRONT);
    static bool isLoss(const QString& category);

private:
    Ui::dbinterface *ui;

private slots:
    void makeTransAction();
    void on_select_clicked();
};

#endif // DBINTERFACE_H
