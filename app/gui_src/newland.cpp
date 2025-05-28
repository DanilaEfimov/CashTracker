#include "gui_src/newland.h"
#include "ui_newland.h"
#include "protocolmanager.h"
#include "logger.h"

newland::newland(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newland)
{
    ui->setupUi(this);
    this->init();
}

newland::~newland()
{
    delete ui;
}

void newland::init()
{
    ui->textEdit->setReadOnly(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
void newland::initTable(const QStringList& fields)
{
    int rows = ui->tableWidget->rowCount();
    int cols = ui->tableWidget->columnCount();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int index = i * cols + j;
            if (index >= fields.size()) break;

            QTableWidgetItem* item = ui->tableWidget->item(i, j);
            if (!item) {
                item = new QTableWidgetItem();
                ui->tableWidget->setItem(i, j, item);
            }
            item->setText(fields.at(index));
        }
    }
}


void newland::on_update_btn_clicked()
{
    protocol request;
    request.util_name       = py_utils[network_py];
    request.function_name   = py_funs[update_crypto_rates];

    protocolManager::sendRequest(request);
    int exit_code = protocolManager::runBackend();

    int answer = protocolManager::readAnswer();
    if(answer){
        #ifdef QT_DEBUG
            qDebug() << "non success answer from backend : " << answer;
        #endif
        logger::log("non success answer from backend : " + QString::number(answer));
        return;
    }

    QStringList values;
    for(int i = 0; i < ui->tableWidget->rowCount()*ui->tableWidget->columnCount(); i++) {
        values.append(protocolManager::readLine(i+1));
    }

    this->initTable(values);

    if(exit_code){
        QString moment = QDateTime::currentDateTime().toString();
        logger::log("Args: \nconverter request was finished with fatal exit code "
                    + QString::number(exit_code) + " :: " + moment);
    }
}

