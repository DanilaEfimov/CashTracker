#include "gui_src/noteinterface.h"
#include "ui_noteinterface.h"
#include "logger.h"
#include "dbmanager.h"

#include <QDateTime>

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

void noteinterface::on_maketransaction_clicked()
{
    QString amountstr = ui->amountval->text();
    bool ok = false;
    double amount = amountstr.toDouble(&ok);

    // by default Ypu have to contain #CUR short name in first 3 chars
    QString currency = ui->currencyval->currentText().mid(0,3);
    QString category = ui->categoriesval->currentText();
    QDate date = ui->dateval->date();
    QDate today = QDate::currentDate();

    QString moment = QDateTime::currentDateTime().toString();
    if(date > today || !ok){
        Dialog::throwWarning("invalid input", "check Your input: amount, and all that...");
        logger::log("strange input :: noteinterface :: make transaction" + moment);
        return;
    }

    int id = dbmanager::getID();
    bool success = dbmanager::insertTransaction(amount, category, date.toString(), currency, id);

    if(!success){
        Dialog::throwWarning("DB issues", "somethnig went wrong, try later");
        logger::log("can not insert :: noteinterface :: make transaction" + moment);
        return;
    }

    QString comment = ui->commentedit->toPlainText().trimmed();
    if(comment != ""){
        success = dbmanager::insertComment(id, comment);
        if(!success){
            Dialog::throwWarning("DB issues", "somethnig went wrong, try later");
            logger::log("can not insert :: noteinterface :: insert comment" + moment);
            return;
        }
    }
}


void noteinterface::on_makepurpose_clicked()
{
    QString amountstr = ui->amountval->text();
    bool ok = false;
    double amount = amountstr.toDouble(&ok);

    // by default Ypu have to contain #CUR short name in first 3 chars
    QString currency = ui->currencyval->currentText().mid(0,3);
    QDate date = ui->dateval->date();
    QDate today = QDate::currentDate();

    QString moment = QDateTime::currentDateTime().toString();
    if(date <= today || !ok){
        Dialog::throwWarning("invalid input", "amount inputed uncorrectly\nor date too past");
        logger::log("strange input :: noteinterface :: make transaction" + moment);
        return;
    }

    int id = dbmanager::getID();
    bool success = dbmanager::insertPurpose(amount, date.toString(), currency, id);

    if(!success){
        Dialog::throwWarning("DB issues", "somethnig went wrong, try later");
        logger::log("can not insert :: noteinterface :: make purpose" + moment);
        return;
    }

    QString comment = ui->commentedit->toPlainText().trimmed();
    if(comment != ""){
        success = dbmanager::insertComment(id, comment);
        if(!success){
            Dialog::throwWarning("DB issues", "maybe such deadline exist yet");
            logger::log("can not insert :: noteinterface :: insert comment" + moment);
            return;
        }
    }
}

