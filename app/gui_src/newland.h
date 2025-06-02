#ifndef NEWLAND_H
#define NEWLAND_H

#include <QWidget>

#include "protocolmanager.h"

namespace Ui {
class newland;
}

class newland : public QWidget
{
    Q_OBJECT

public:
    explicit newland(QWidget *parent = nullptr);
    ~newland();

private slots:
    void on_update_btn_clicked();

    void on_export_btn_clicked();

private:
    Ui::newland *ui;

    void init();
    void initTable(const QStringList& fields);
    void readData(data_t& args) const;
};

#endif // NEWLAND_H
