#ifndef CONVERTER_H
#define CONVERTER_H

#include <QWidget>

namespace Ui {
class converter;
}

class converter : public QWidget
{
    Q_OBJECT

public:
    explicit converter(QWidget *parent = nullptr);
    ~converter();

private slots:
    void on_convert_btn_clicked();

private:
    Ui::converter *ui;
};

#endif // CONVERTER_H
