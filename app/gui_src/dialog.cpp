#include "dialog.h"
#include "ui_dialog.h"
#include "general.h"

#include <QFile>
#ifdef QT_DEBUG
    #include <QDebug>
#endif
#include <QFileDialog>

Dialog::Dialog(QWidget *parent, const QString& msg)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    this->m_data = {};

    this->setWindowTitle(msg);
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
    this->exec();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::throwWarning(const QString& title, const QString& info)
{
    QIcon ico(ICON_WARNINGS);
    QMessageBox warning;
    warning.setIconPixmap(ico.pixmap(32,32));
    warning.setText(info);
    warning.setWindowTitle(title);
    warning.exec();
}

void Dialog::getData(dialog_data &data) const
{
    data.path = ui->path_input->text();
}

void Dialog::on_browse_btn_clicked()
{
    const QString path = QFileDialog::getExistingDirectory();
    ui->path_input->setText(path);
}

void Dialog::on_ok_btn_clicked()
{
    this->m_data.path = ui->path_input->text();
    this->close();
}

