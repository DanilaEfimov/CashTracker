#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "general.h"

#include <QSqlDatabase>

class dbmanager {
public:
    static void connect(const QString& dbpath = DB_PATH);
    static void disconnect();
    static bool insertTransaction(double amount, const QString &category,
                                  const QString &date, const QString &currency, int id);
    static void incrementID();
    static int getID();

private:
    static QSqlDatabase db;
    static int id;
    static bool connected;

    static int getCurID();
};

#endif // DBMANAGER_H
