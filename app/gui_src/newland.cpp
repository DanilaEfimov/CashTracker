#include "gui_src/newland.h"
#include "ui_newland.h"
#include "logger.h"
#include "general.h"

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

void newland::readData(data_t &args) const
{
    int cols = ui->tableWidget->columnCount();
    int rows = ui->tableWidget->rowCount();
    if(cols == 0 || rows == 0){
        return;
    }

    args.nums.append(rows); // count of currencies
    args.nums.append(cols);    // vvv count of attributes json object's vvv
    args.str.append(reverseCurs[USD]);
    args.str.append(reverseCurs[EUR]);

    for (int i = 0; i < rows; ++i) {
        QTableWidgetItem* headerItem = ui->tableWidget->verticalHeaderItem(i);
        if (!headerItem) {
            args.clear();
            return;
        }

        QString currency = headerItem->text();
        if (currency.isEmpty()) {
            args.clear();
            return;
        }

        args.str.append(currency);

        for (int j = 0; j < cols; ++j) {
            QTableWidgetItem* item = ui->tableWidget->item(i, j);
            if (!item || item->text().isEmpty()) {
                args.clear();
                return;
            }
            args.readArg(item->text(), REAL_T);
        }
    }
}

void newland::on_update_btn_clicked()
{
    protocol request;
    request.util_name       = py_utils[network_py];
    request.function_name   = py_funs[update_crypto_rates];

    protocolManager::writeArgs(data_t());
    protocolManager::sendRequest(request);
    int exit_code = protocolManager::runBackend();

    int answer = protocolManager::readAnswer();
    if(answer){
        QString error = reverseCodes[answer];
        Dialog::throwWarning(error, "something went wrong, IPC return " + error);
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

    request.function_name   = py_funs[update_crypto_news];
    protocolManager::sendRequest(request);
    exit_code = protocolManager::runBackend();
    answer = protocolManager::readAnswer();

    if(answer){
        QString error = reverseCodes[answer];
        Dialog::throwWarning(error, "something went wrong, IPC return " + error);
        #ifdef QT_DEBUG
            qDebug() << "non success answer from backend : " << answer;
        #endif
        logger::log("non success answer from backend : " + QString::number(answer));
        return;
    }

    QString news = "";
    protocolManager::readAll(news);
    ui->textEdit->setText(news);

    if(exit_code){
        QString moment = QDateTime::currentDateTime().toString();
        logger::log("Args: \nconverter request was finished with fatal exit code "
                    + QString::number(exit_code) + " :: " + moment);
    }
}

void newland::on_export_btn_clicked()
{
    dialog_data path;
    Dialog pathBrowser(nullptr, "choise directory path");
    pathBrowser.getData(path);
    QString format = ui->formats->currentText();

    data_t args;
    this->readData(args);
    if(args.empty()){   // empty table branch
        return;
    }

    args.str.append(format);
    args.readDialogData(path);
    protocolManager::writeArgs(args);

    protocol request;
    request.util_name       = py_utils[parser_py];

    if(format == JSON)      { request.function_name = py_funs[save_as_json];}
    else if(format == CSV)  { request.function_name = py_funs[save_as_csv]; }
    else{
        #ifdef QT_DEBUG
            qDebug() << "undefined file format ::newland::on_export...event";
        #endif
        logger::log("something strange, man, undefined file format was given :: " +
                        QDateTime::currentDateTime().toString());
        return;
    }

    protocolManager::sendRequest(request);
    int exit_code = protocolManager::runBackend();

    if(exit_code){
        logger::log("exit code from py_backend : " + QString::number(exit_code) +
                    " :: " + QDateTime::currentDateTime().toString());
        return;
    }

    int answer = protocolManager::readAnswer();
    if(answer){
        logger::log("answer from py_backend : " + reverseCodes[answer] +
                    " :: " + QDateTime::currentDateTime().toString());
        return;
    }
}

