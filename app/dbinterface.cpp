#include "dbinterface.h"
#include "ui_dbinterface.h"

dbinterface::dbinterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dbinterface)
{
    ui->setupUi(this);
}

dbinterface::~dbinterface()
{
    delete ui;
}
