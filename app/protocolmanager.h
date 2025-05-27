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

struct data_t {

    // example of data_t struct
    // more in doc/api

    QVector<double> dbl;
    QVector<int> nums;
    QVector<QString> str;
    QVector<QDate> dates;

    data_t() : dbl(), nums(), str(), dates() {};

    void readArg(const QString& value, const QString& sign);
    QString signature() const;
    QString argcounts() const;
    QStringList values() const;
};

class protocolManager : QObject
{
    Q_OBJECT;

public:
    protocolManager() = default;

    static int sendRequest(const protocol& request, const QString path = BUFFER_PATH);
    static int readAnswer(const QMap<QString, int> & exits = codes,
                          const QString path = RESPONSE_PATH);

    static int readArgs(data_t& response, const QString path = RESPONSE_PATH);
    static int writeArgs(const data_t& response, const QString path = RESPONSE_PATH);

    static int runBackend(const QString& path = PY_BACK_PATH);
    static int runUtil(const QStringList& argv, const QString& path);
};

#endif // PROTOCOLMANAGER_H
