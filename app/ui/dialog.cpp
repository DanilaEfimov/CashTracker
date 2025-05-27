#include "dialog.h"
#include "ui_dialog.h"

#include <QFile>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QFile style();
}

Dialog::~Dialog()
{
    delete ui;
}
