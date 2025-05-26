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

private:
    Ui::converter *ui;
};

#endif // CONVERTER_H
