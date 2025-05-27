#ifndef PROGRESS_H
#define PROGRESS_H

#include <QWidget>
#include <QGraphicsView>

namespace Ui {
class progress;
}

class progress : public QWidget
{
    Q_OBJECT

public:
    explicit progress(QWidget *parent = nullptr);
    ~progress();

private:
    Ui::progress *ui;
    QGraphicsView* graphic;
};

#endif // PROGRESS_H
