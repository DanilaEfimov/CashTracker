#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gui_src/converter.h"
#include "gui_src/progress.h"
#include "gui_src/noteinterface.h"
#include "gui_src/dbinterface.h"
#include "gui_src/newland.h"

#include <QMainWindow>
#include <QStackedWidget>
#include <QActionGroup>
#include <QProcess>

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
    newland* news_w;

    QProcess* utilit;

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
