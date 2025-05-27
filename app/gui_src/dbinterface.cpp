#include "gui_src/dbinterface.h"
#include "ui_dbinterface.h"
#include "protocolmanager.h"
#include "dbmanager.h"

#include <QFile>
#ifdef QT_DEBUG
    #include <QDebug>
#endif
#include <QTextStream>

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

int dbinterface::logErr(const QString &what, const QString &path)
{
    QFile log(path);
    log.open(QIODevice::Append | QIODevice::Text);

    if(!log.isOpen()){
        #ifdef QT_DEBUG
            qDebug() << "failed to open file " << path
                     << " [" << log.errorString() << "]\n";
        #endif
        return openfile_err;
    }

    QTextStream ts(&log);
    ts << what;

    log.close();
    return success;
}

bool dbinterface::isLoss(const QString &category)
{
    try{
        return isloss[category];
    }
    catch(...){
        #ifdef QT_DEBUG
            qDebug() << "invalid argument dbinterface::isLoss"
                 << " [" << category << "]\n";
        #endif
    }
    return false;
}

void dbinterface::makeTransAction()
{
    bool valid_input = false;
    double amount = ui->categories->currentText().toDouble();
    if(!valid_input){
        #ifdef QT_DEBUG
            qDebug() << "invalid input in " << ui->categories->objectName()
                << " [" << amount << "]";
        #endif
        return;
    }

    QString category = ui->categories->currentText();
    QDate today = QDate::currentDate();
    QString currency = ui->currs->currentText().mid(0,2);
    int id = dbmanager::getID();
}

void dbinterface::on_select_clicked()
{
    // check buttons triggers
    bool less = ui->checkless->isTristate();
    bool greater = ui->checkgreater->isTristate();
    bool from = ui->checkfrom->isTristate();
    bool to = ui->checkto->isTristate();

    QString args = "";
}

