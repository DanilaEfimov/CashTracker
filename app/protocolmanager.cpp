#include "protocolmanager.h"
#include "general.h"

#include <QFile>
#include <QTextStream>
#ifndef QT_NO_DEBUG
    #include <QDebug>
#endif

int protocolManager::sendRequest(const protocol &request, const QString path)
{
    QFile buffer(path);
    buffer.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!buffer.isOpen()){
        #ifndef QT_NO_DEBUG
            qDebug() << "failed to open " << path
                 << "\n[" << buffer.errorString() << "]";
        #endif
        return -1; // not ok
    }

    buffer.flush(); // clean
    QTextStream ts(&buffer);
    ts << request.util_name << "\n";
    ts << request.function_name << "\n";
    ts << request.args << "\n";

    buffer.close();

    return 0;
}

int protocolManager::readAnswer(const QMap<QString, int> & exits, const QString path)
{
    // default parameters from general.h
    // more in docs/api

    QFile answer(path);
    answer.open(QIODevice::ReadOnly);

    if(!answer.isOpen()){
        #ifndef QT_NO_DEBUG
            qDebug() << "failed to open " << path
                     << "\n[" << answer.errorString() << "]";
        #endif
        return openfile_err;
    }

    QTextStream ts(&answer);
    QString res = ts.readLine();

    if(exits.find(res) != exits.end()){
        return exits[res];
    }

    return undefined;
}

int protocolManager::readArgs(data &response, const QString path)
{
    // default parameters from general.h
    // more in doc/api

    QFile args(path);
    args.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!args.isOpen()){
        #ifndef QT_NO_DEBUG
            qDebug() << "failed to open " << path
                 << "\n[" << args.errorString() << "]";
        #endif
        args.close();
        return openfile_err;
    }

    QTextStream ts(&args);
    QString line = ts.readLine();
    QStringList sign = line.split(',');

    for (int i = 0; i < sign.size(); i++) {
        line = ts.readLine();
        if (line.isNull()) {
            #ifndef QT_NO_DEBUG
                qDebug() << "uncorrect response file format "
                    << path;
            #endif
            args.close();
            return parse_err;
        }

        // trimmed for rmoving pre/post-fix spaces/tabs/new-line-char
        response.readArg(line.trimmed(), sign[i].trimmed());
    }

    return success;
}

// data defines vvv / protocolManager ^^^

void data::readArg(const QString &value, const QString &sign)
{
    // types from general.h / more in doc/api
    if(sign == TEXT_T)      {this->str.append(value);}
    else if(sign == REAL_T) {this->dbl.append(value.toDouble());}
    else if(sign == INT_T)  {this->nums.append(value.toInt());}
    else if(sign == DATE_T) {this->dates.append(QDate::fromString(value));}
    #ifndef QT_NO_DEBUG
        qDebug() << "undefined argument type [data::readArg] "
            << sign;
    #endif
}
