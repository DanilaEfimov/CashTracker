#include "dbmanager.h"
#include "logger.h"

#ifdef QT_DEBUG
    #include <QDebug>
#endif
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>

QSqlDatabase dbmanager::db = {};    // QSqlDatabase::addDatabase("QSQLITE");
int dbmanager::id = -1;
bool dbmanager::connected = false;

void dbmanager::connect(const QString &dbpath)
{
    if (connected)
        return;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbpath);
    if (!db.open()) {
        #ifdef QT_DEBUG
            qDebug() << "Failed to open database:" << db.lastError().text();
        #endif
        return;
    }

    connected = true;
    id = getCurID();    // if something went wrong then returns -1 (fatal error)
    if(id == fatal_err){
        QString moment = QDateTime::currentDateTime().toString();
        logger::log("fatal error : failed to initialize ENTITIES count :: " + moment);
    }
}

int dbmanager::getCurID()
{
    if (!db.isOpen()) {
        #ifdef QT_DEBUG
            qDebug() << "Database not open!";
        #endif
        return fatal_err;
    }

    QSqlQuery query(db);
    query.prepare("SELECT value FROM settings WHERE setting = 'entities'");
    query.bindValue(":setting", ENTITIES);

    if (!query.exec()) {
        #ifdef QT_DEBUG
            qDebug() << "Query failed:" << query.lastError().text();
        #endif
        return fatal_err;
    }

    if (query.next()) {
        return query.value(0).toInt();
    }

    #ifdef QT_DEBUG
        qDebug() << "FATAL ERROR : cannot init ID";
    #endif
    return fatal_err;
}

void dbmanager::updateTotal(const QString &delta)
{
    if (!db.isOpen()) {
        #ifdef QT_DEBUG
            qDebug() << "Database not open!";
        #endif
        return;
    }

    QSqlQuery query(db);

    query.prepare("SELECT value FROM general WHERE parameter = 'total'");
    if (!query.exec()) {
        #ifdef QT_DEBUG
            qDebug() << "Failed to fetch current value of 'total':" << query.lastError().text();
        #endif
        return;
    }

    double currentValue = 0.0;
    if (query.next()) {
        currentValue = query.value(0).toDouble();
    } else {
        #ifdef QT_DEBUG
            qDebug() << "No entry found for parameter = 'total'";
        #endif
        return;
    }

    double deltaValue = delta.toDouble();
    double newValue = currentValue + deltaValue;
    QString value = QString::number(newValue);

    query.prepare("UPDATE general SET value = :value WHERE parameter = :name");
    query.bindValue(":name", "total");
    query.bindValue(":value", value);

    if (!query.exec()) {
        #ifdef QT_DEBUG
            qDebug() << "Failed to update general values:" << query.lastError().text();
        #endif
        QString moment = QDateTime::currentDateTime().toString();
        logger::log("Fatal error, failed to update general :: " + moment);
        return;
    }
}

void dbmanager::updateEntities(const QString &value)
{
    if (!db.isOpen()) {
        #ifdef QT_DEBUG
            qDebug() << "Database not open!";
        #endif
        return;
    }

    QSqlQuery query(db);

    query.prepare("UPDATE settings SET value = :value WHERE setting = :setting");
    query.bindValue(":value", value);
    query.bindValue(":setting", "entities");

    if (!query.exec()) {
        #ifdef QT_DEBUG
            qDebug() << "Failed to update 'entities' setting:" << query.lastError().text();
        #endif
        QString moment = QDateTime::currentDateTime().toString();
        logger::log("Fatal error, failed to update entities setting :: " + moment);
        return;
    }
}

bool dbmanager::isLoss(const QString &category)
{
    try{
        return isloss[category];
    }
    catch(...){
        return false;
    }
}

bool dbmanager::insertTransaction(double amount, const QString &category, const QString &date, const QString &currency, int id)
{
    if (!db.isOpen()) {
        #ifdef QT_DEBUG
            qDebug() << "Database not open!";
        #endif
        return false;
    }

    QSqlQuery query(db);
    if(isLoss(category)){amount = -amount;}

    query.prepare("INSERT INTO transactions (amount, category, date, currency, id) "
                  "VALUES (:amount, :category, :date, :currency, :id)");
    query.bindValue(":amount", amount);
    query.bindValue(":category", category);
    query.bindValue(":date", date);
    query.bindValue(":currency", currency);
    query.bindValue(":id", id);

    if (!query.exec()) {
        #ifdef QT_DEBUG
            qDebug() << "Insert failed:" << query.lastError().text();
        #endif
        QString moment = QDateTime::currentDateTime().toString();
        logger::log("failed to insert :: DB :: inserttransaction " + moment);
        return false;
    }

    updateTotal(QString::number(amount));

    incrementID();
    return true;
}

bool dbmanager::insertComment(int id, const QString &comment)
{
    if (!db.isOpen()) {
        #ifdef QT_DEBUG
            qDebug() << "Database not open!";
        #endif
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO comments (id, comment) "
                  "VALUES (:id, :comment)");
    query.bindValue(":id", id);
    query.bindValue(":comment", comment);

    if(!query.exec()) {
        #ifdef QT_DEBUG
            qDebug() << "Insert failed:" << query.lastError().text();
        #endif
        QString moment = QDateTime::currentDateTime().toString();
        logger::log("failed to insert :: DB :: insertcomment " + moment);
        return false;
    }

    return true;
}

bool dbmanager::insertPurpose(double amount, const QString &deadline, const QString &currency, int id)
{
    if (!db.isOpen()) {
        #ifdef QT_DEBUG
            qDebug() << "Database not open!";
        #endif
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO purposes (amount, deadline, currency, id, success) "
                  "VALUES (:amount, :deadline, :currency, :id, :success)");
    query.bindValue(":amount", amount);
    query.bindValue(":deadline", deadline);
    query.bindValue(":currency", currency);
    query.bindValue(":id", id);
    query.bindValue(":success", 0);

    if (!query.exec()) {
        #ifdef QT_DEBUG
            qDebug() << "Insert failed:" << query.lastError().text();
        #endif
        QString moment = QDateTime::currentDateTime().toString();
        logger::log("failed to insert :: DB :: insertPurpose " + moment);
        return false;
    }

    incrementID();
    return true;
}

void dbmanager::disconnect()
{
    if (connected && db.isOpen()) {
        db.close();
        connected = false;
    }
}

void dbmanager::incrementID()
{
    id++;
    updateEntities(QString::number(id));
}

int dbmanager::getID()
{
    return id;
}

void dbmanager::select(const protocol &proto, const data_t &data)
{
    int res = protocolManager::sendRequest(proto);
    if(res){
        #ifdef QT_DEBUG
            qDebug() << "failed request sending status";
            logger::log("failed to send request, status : " + QString::number(res)
                        + " " + QDate::currentDate().toString());
        #endif
        return;
    }

    protocolManager::writeArgs(data);
    int status = protocolManager::runBackend();

    if(status){
        #ifdef QT_DEBUG
            qDebug() << "failed run status";
        #endif
        return;
    }
}
