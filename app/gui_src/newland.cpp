#include "gui_src/newland.h"
#include "ui_newland.h"
#include "protocolmanager.h"

newland::newland(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newland)
{
    ui->setupUi(this);
}

newland::~newland()
{
    delete ui;
}
