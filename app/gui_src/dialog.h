#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

struct dialog_data {
    QString path;
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, const QString& msg = "");
    ~Dialog();

    static void throwWarning(const QString& title, const QString& info);

    void getData(dialog_data& data) const;

private slots:
    void on_browse_btn_clicked();
    void on_ok_btn_clicked();

private:
    Ui::Dialog *ui;
    dialog_data m_data;
};

#endif // DIALOG_H
