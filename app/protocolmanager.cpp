#include "protocolmanager.h"
#include "general.h"
#include "logger.h"

#include <QFile>
#include <QTextStream>
#ifdef QT_DEBUG
    #include <QDebug>
#endif
#include <QProcess>

int protocolManager::sendRequest(const protocol &request, const QString path)
{
    QFile buffer(path);
    buffer.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!buffer.isOpen()){
        #ifdef QT_DEBUG
            qDebug() << "failed to open " << path
                 << "\n[" << buffer.errorString() << "]";
        #endif
        return -1; // not ok
    }

    buffer.flush(); // clean
    QTextStream ts(&buffer);
    ts << request.util_name << "\n";
    ts << request.function_name << "\n";
    buffer.close();
    return 0;
}

int protocolManager::readAnswer(const QMap<QString, int> & exits, const QString path)
{
    // default parameters from general.h
    // more in docs/api

    QFile answer(path);
    answer.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!answer.isOpen()){
        #ifdef QT_DEBUG
            qDebug() << "failed to open " << path
                     << "\n[" << answer.errorString() << "]";
        #endif
        return openfile_err;
    }

    QTextStream ts(&answer);
    QString res = ts.readLine();
    answer.close();

    if(exits.find(res) != exits.end()){
        return exits[res];
    }

    return undefined;
}

QString protocolManager::readLine(size_t col, const QString path)
{
    // default parameters from general.h
    // more in docs/api

    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!file.isOpen()){
        #ifdef QT_DEBUG
            qDebug() << "failed to open " << path
                    << "\n[" << file.errorString() << "]";
        #endif
        return "";
    }

    QTextStream in(&file);
    QString line;
    size_t currentLine = 0;

    while (!in.atEnd()) {
        line = in.readLine();
        if (currentLine == col)
            return line;
        ++currentLine;
    }

    #ifdef QT_DEBUG
        qDebug() << "cannot read line " << col << " from " << path;
    #endif
    logger::log("cannot read line " + QString::number(col) + " from " + path);

    return "";
}

int protocolManager::readArgs(data_t &response, const QString path)
{
    // default parameters from general.h
    // more in doc/api

    QFile args(path);
    args.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!args.isOpen()){
        #ifdef QT_DEBUG
            qDebug() << "failed to open " << path
                 << "\n[" << args.errorString() << "]";
        #endif
        return openfile_err;
    }

    QTextStream ts(&args);
    QString line = ts.readLine();
    QStringList sign = line.split(',', Qt::SkipEmptyParts);
    QStringList argc = line.split(',', Qt::SkipEmptyParts);

    for (int i = 0; i < sign.size(); i++) {
        for(auto count : argc){
            line = ts.readLine();
            if (line.isNull()) {
                #ifdef QT_DEBUG
                    qDebug() << "uncorrect response file format "
                        << path;
                #endif
                args.close();
                return parse_err;
            }
            // trimmed for rmoving pre/post-fix spaces/tabs/new-line-char
            response.readArg(line.trimmed(), sign[i].trimmed());
        }
    }

    args.close();
    return success;
}

int protocolManager::writeArgs(const data_t &response, const QString path)
{
    QFile args(path);
    args.open(QIODevice::WriteOnly | QIODevice::Text);

    args.flush();   // clear

    if(!args.isOpen()){
        #ifdef QT_DEBUG
            qDebug() << "failed to open " << path
                     << "\n[" << args.errorString() << "]";
        #endif
        return openfile_err;
    }

    QTextStream ts(&args);
    ts << response.signature(); Qt::endl(ts);
    ts << response.argcounts(); Qt::endl(ts);
    ts << response.values().join('\n'); Qt::endl(ts);

    args.close();
    return success;
}

int protocolManager::runBackend(const QString& path)
{
    QProcess process;
    process.setProgram("cmd");
    process.setArguments({ "/c", "run_backend.bat" });
    process.setWorkingDirectory("../py_backend");
    process.setProcessChannelMode(QProcess::MergedChannels);

    process.start();

    if (!process.waitForStarted()) {
        #ifdef QT_DEBUG
            qDebug() << "Failed to start backend process";
        #endif
        return run_err;
    }

    if (!process.waitForFinished()) {
        #ifdef QT_DEBUG
            qDebug() << "Process did not finish in time";
        #endif
        return run_err;
    }

    int exit_code = process.exitCode();

    #ifdef QT_DEBUG
        qDebug() << "Backend process finished with code:" << exit_code;
        qDebug() << "Output:" << process.readAllStandardOutput();
    #endif

    return (exit_code == 0) ? success : run_err;
}


int protocolManager::runUtil(const QStringList& argv, const QString& path)
{
    QProcess util;
    util.start(path, argv);

    if(!util.waitForStarted()){
        #ifdef QT_DEBUG
            qDebug() << "failed to run util " << path
                << "\nabout:\n" << util.errorString();
        #endif
        return run_err;
    }

    return success;
}

// data_t defines vvv / protocolManager ^^^

void data_t::readArg(const QString &value, const QString &sign)
{
    // types from general.h / more in doc/api
    if(sign == TEXT_T)      {this->str.append(value);}
    else if(sign == REAL_T) {this->dbl.append(value.toDouble());}
    else if(sign == INT_T)  {this->nums.append(value.toInt());}
    else if(sign == DATE_T) {this->dates.append(QDate::fromString(value));}
    else {
    #ifdef QT_DEBUG
        qDebug() << "undefined argument type [data::readArg] "
            << sign;
    #endif
    }
}

QString data_t::signature() const
{
    QStringList signs;
    if(!this->str.empty())      {signs.append(TEXT_T);}
    if(!this->nums.empty())     {signs.append(INT_T);}
    if(!this->dbl.empty())      {signs.append(REAL_T);}
    if(!this->dates.empty())    {signs.append(DATE_T);}
    QString res = signs.join(',');
    return res;
}

QString data_t::argcounts() const
{
    QStringList counts;
    if(this->str.size())    {counts.append(QString::number(this->str.size()));}
    if(this->nums.size())   {counts.append(QString::number(this->nums.size()));}
    if(this->dbl.size())    {counts.append(QString::number(this->dbl.size()));}
    if(this->dates.size())  {counts.append(QString::number(this->dates.size()));}
    QString res = counts.join(',');
    return res;
}

QStringList data_t::values() const
{
    QStringList values;
    for(auto& val : this->str)      {values.append(val);}
    for(auto& val : this->nums)     {values.append(QString::number(val));}
    for(auto& val : this->dbl)      {values.append(QString::number(val));}
    for(auto& val : this->dates)    {values.append(val.toString());}
    return values;
}
