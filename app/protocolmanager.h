#ifndef PROTOCOLMANAGER_H
#define PROTOCOLMANAGER_H

#include "general.h"

#include <QString>
#include <QMap>
#include <QVector>
#include <QTextStream>
#include <QDate>
#include <QWidget>

struct protocol{
    QString util_name;
    QString function_name;
    QString args;
};

struct data {

    // example of data struct
    // more in doc/api

    QVector<double> dbl;
    QVector<int> nums;
    QVector<QString> str;
    QVector<QDate> dates;

    data() : dbl(), nums(), str(), dates() {};

    void readArg(const QString& value, const QString& sign);
};

class protocolManager
{
public:
    protocolManager() = default;

    static int sendRequest(const protocol& request, const QString path = BUFFER_PATH);
    static int readAnswer(const QMap<QString, int> & exits = codes,
                          const QString path = RESPONSE_PATH);

    static int readArgs(data& response, const QString path = RESPONSE_PATH);

    static int runBackend(const QString& path);
    static int runUtil(const QStringList& argv, const QString& path);
};

#endif // PROTOCOLMANAGER_H
