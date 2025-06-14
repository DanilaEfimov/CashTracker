#ifndef PROTOCOLMANAGER_H
#define PROTOCOLMANAGER_H

#include "general.h"    // here included /gui_src/dialog.h

#include <QString>
#include <QMap>
#include <QVector>
#include <QTextStream>
#include <QDate>
#include <QWidget>

struct protocol{
    QString util_name;
    QString function_name;
};

struct data_t {

    // example of data_t struct
    // more in doc/api

    QVector<QString> str;
    QVector<QDate> dates;
    QVector<double> dbl;
    QVector<int> nums;
    QVector<bool> flags;

    data_t() : str(), dates(), dbl(), nums(), flags() {};

    void readArg(const QString& value, const QString& sign);
    void readDialogData(const dialog_data& data);
    QString signature() const;
    QString argcounts() const;
    QStringList values() const;

    bool empty() const;
    void clear();
};

class protocolManager : QObject
{
    Q_OBJECT;

public:
    protocolManager() = default;

    static int sendRequest(const protocol& request, const QString path = BUFFER_PATH);
    static int readAnswer(const QMap<QString, int> & exits = codes,
                          const QString path = RESPONSE_PATH);
    static QString readLine(size_t col = 0, const QString path = RESPONSE_PATH);
    static void readAll(QString& str, const QString path = RESPONSE_PATH);

    static int readArgs(data_t& response, const QString path = RESPONSE_PATH);
    static int writeArgs(const data_t& response, const QString path = ARGUMENT_PATH);

    static int runBackend(const QString& path = OS_CALL_BACKEND_PATH);
    static int runUtil(const QStringList& argv, const QString& path);
};

#endif // PROTOCOLMANAGER_H
