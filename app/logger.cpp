#include "logger.h"

#include <QFile>
#include <QDateTime>
#ifdef QT_DEBUG
    #include <QDebug>
#endif

int logger::log(const QString what, const QString &path)
{
    QFile logs(path);
    logs.open(QIODevice::Append | QIODevice::Text);

    if(!logs.isOpen()){
        #ifdef QT_DEBUG
            qDebug() << what;
        #endif
        return openfile_err;
    }

    QTextStream ts(&logs);
    ts << what; Qt::endl(ts);

    logs.close();
    return success;
}
