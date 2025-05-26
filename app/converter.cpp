#include "converter.h"
#include "ui_converter.h"

converter::converter(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::converter)
{
    ui->setupUi(this);
}

converter::~converter()
{
    delete ui;
}
