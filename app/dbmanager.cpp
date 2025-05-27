#include "dbmanager.h"
#ifdef QT_DEBUG
    #include <QDebug>
#endif
#include <QSqlQuery>
#include <QSqlError>

QSqlDatabase dbmanager::db = QSqlDatabase::addDatabase("QSQLITE");
int dbmanager::id = -1;
bool dbmanager::connected = false;

void dbmanager::connect(const QString &dbpath)
{
    if (connected)
        return;

    db.setDatabaseName(dbpath);
    if (!db.open()) {
        #ifdef QT_DEBUG
            qDebug() << "Failed to open database:" << db.lastError().text();
        #endif
        return;
    }

    connected = true;
    id = getCurID();
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
    query.prepare("SELECT id FROM settings WHERE setting = :setting");
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

bool dbmanager::insertTransaction(double amount, const QString &category, const QString &date, const QString &currency, int id)
{
    if (!db.isOpen()) {
        #ifdef QT_DEBUG
            qDebug() << "Database not open!";
        #endif
        return false;
    }

    QSqlQuery query(db);
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
}

int dbmanager::getID()
{
    return id;
}
