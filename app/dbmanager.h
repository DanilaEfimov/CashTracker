#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "general.h"

#include <QSqlDatabase>

class dbmanager {
public:
    static void connect(const QString& dbpath);
    static void disconnect();
    static int getCurID();
    static bool insertTransaction(double amount, const QString &category, const QString &date, const QString &currency, int id);
    static void incrementID();

private:
    static QSqlDatabase db;
    static int id;
    static bool connected;
};

#endif // DBMANAGER_H
