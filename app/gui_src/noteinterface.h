#ifndef NOTEINTERFACE_H
#define NOTEINTERFACE_H

#include <QWidget>

namespace Ui {
class noteinterface;
}

class noteinterface : public QWidget
{
    Q_OBJECT

public:
    explicit noteinterface(QWidget *parent = nullptr);
    ~noteinterface();

private:
    Ui::noteinterface *ui;

private slots:
    void on_maketransaction_clicked();
    void on_makepurpose_clicked();
};

#endif // NOTEINTERFACE_H
