#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "converter.h"
#include "progress.h"
#include "noteinterface.h"
#include "dbinterface.h"

#include <QMainWindow>
#include <QStackedWidget>
#include <QActionGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    QStackedWidget* views;
    QActionGroup* themes_menu;

    converter* converter_w;
    progress* progress_w;
    noteinterface* noteint_w;
    dbinterface* dbint_w;

    void init();
    void setupStyle();
    void setupStack();
    void setupBibds();
    void setupMenuBar();

public slots:
    void setLightTheme();
    void setDarkTheme();
};

#endif // MAINWINDOW_H
