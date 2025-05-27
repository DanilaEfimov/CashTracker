#include "gui_src/progress.h"
#include "ui_progress.h"

progress::progress(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::progress)
{
    ui->setupUi(this);
}

progress::~progress()
{
    delete ui;
}
