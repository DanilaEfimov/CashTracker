#include "noteinterface.h"
#include "ui_noteinterface.h"

noteinterface::noteinterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::noteinterface)
{
    ui->setupUi(this);
}

noteinterface::~noteinterface()
{
    delete ui;
}
