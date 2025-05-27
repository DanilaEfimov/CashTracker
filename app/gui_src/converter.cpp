#include "gui_src/converter.h"
#include "ui_converter.h"
#include "dbinterface.h"
#include "protocolmanager.h"
#include "logger.h"

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

void converter::on_convert_btn_clicked()
{
    QString tempcur = ui->fromcur->currentText().mid(0,3);
    QString targetcur = ui->tocur->currentText().mid(0,3);

    bool valid_input = false;
    double amount = ui->amount_input->text().toDouble(&valid_input);
    if(!valid_input){
        #ifdef QT_DEBUG
            qDebug() << "invalid input in " << ui->amount_input->objectName();
        #endif
        return;
    }

    data_t args;
    args.str.append(tempcur);   // currency, which You have
    args.str.append(targetcur); // currency for convert
    args.dbl.append(amount);    // how many money

    protocol request;
    request.util_name       = py_utils[cache_py];
    request.function_name   = py_funs[get_rates];

    protocolManager::writeArgs(args);
    protocolManager::sendRequest(request);
    int exit_code = protocolManager::runBackend();

    if(exit_code){
        QString moment = QDateTime::currentDateTime().toString();
        logger::log("Args: " + tempcur + ", " + targetcur + ", " + QString::number(amount)
            + "\nconverter request was finished with fatal exit code "
            + QString::number(exit_code) + " :: " + moment);
    }
}

