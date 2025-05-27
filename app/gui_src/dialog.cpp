#include "dialog.h"
#include "ui_dialog.h"
#include "general.h"

#include <QFile>
#ifdef QT_DEBUG
    #include <QDebug>
#endif

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QFile style(QSS_DIALOG);
    style.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!style.isOpen()){
        #ifdef QT_DEBUG
            qDebug() << "failed to open file " << QSS_DIALOG
                << " [" << style.errorString() << "]\n";
        #endif
        return;
    }

    QString str = style.readAll();
    this->setStyleSheet(str);
    style.close();
}

Dialog::~Dialog()
{
    delete ui;
}
