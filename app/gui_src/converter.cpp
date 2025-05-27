#include "gui_src/converter.h"
#include "ui_converter.h"
#include "dbinterface.h"

#ifdef QT_DEBUG
    #include <QDebug>
#endif

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

void converter::on_pushButton_clicked()
{
    QString tempcur = ui->fromcur->currentText().mid(0,2);
    QString tagretcut = ui->tocur->currentText().mid(0,2);

    bool valid_input = false;
    double amount = ui->amount_input->text().toDouble(&valid_input);
    if(!valid_input){
        #ifdef QT_DEBUG
            qDebug() << "invalid input in " << ui->amount_input->objectName();
        #endif
        return;
    }
}

