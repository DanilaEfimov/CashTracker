#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "general.h"
#include "protocolmanager.h"

#include <QSqlDatabase>

class dbmanager {
public:
    static void connect(const QString& dbpath = DB_PATH);
    static void disconnect();
    static bool insertTransaction(double amount, const QString &category,
                                  const QString &date, const QString &currency, int id);
    static bool insertComment(int id, const QString& comment);
    static bool insertPurpose(double aomunt, const QString& date, const QString& currency, int id);
    static void incrementID();
    static int getID();

    static void select(const protocol& proto, const data_t& data);

private:
    static QSqlDatabase db;
    static int id;
    static bool connected;

    static int getCurID();
    static void updateTotal(const QString& delta);
    static void updateEntities(const QString& value);
    static bool isLoss(const QString& category);
};

// TODO: before runing we need to calculate total cash amount by py_backend util

#endif // DBMANAGER_H
