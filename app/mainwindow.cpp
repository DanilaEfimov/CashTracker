#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "general.h"

#include <QFile>
#include <QString>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->init();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete this->converter_w;
    delete this->progress_w;
    delete this->noteint_w;
    delete this->dbint_w;

    delete this->views;
}

void MainWindow::init()
{
    this->setupStack();
    this->setupStyle();
    this->setupBibds();
    this->setupMenuBar();
}

void MainWindow::setupStyle()
{
    // main window
    QFile style(QSS_L_MAIN_PATH);
    style.open(QFile::ReadOnly);
    QString qss = style.readAll();
    this->setStyleSheet(qss);
    style.close();

    //icon
    QIcon icon(ICON_CASHTRACKER);
    this->setWindowIcon(icon);

    this->setWindowTitle("Cash Tracker");
}

void MainWindow::setupStack()
{
    this->views         = new QStackedWidget(this);

    this->converter_w   = new converter(this);
    this->progress_w    = new progress(this);
    this->noteint_w     = new noteinterface(this);
    this->dbint_w       = new dbinterface(this);

    this->views->addWidget(this->converter_w);  // index 0
    this->views->addWidget(this->progress_w);   // index 1
    this->views->addWidget(this->noteint_w);    // index 2
    this->views->addWidget(this->dbint_w);      // index 3

    this->setCentralWidget(this->views);
}

void MainWindow::setupBibds()
{
    // action menu
    connect(ui->actconverter, &QAction::triggered, this, [=](){
        this->views->setCurrentWidget(this->converter_w);
    });
    connect(ui->actprogress, &QAction::triggered, this, [=](){
        this->views->setCurrentWidget(this->progress_w);
    });
    connect(ui->actnoteint, &QAction::triggered, this, [=](){
        this->views->setCurrentWidget(this->noteint_w);
    });
    connect(ui->actdbint, &QAction::triggered, this, [=](){
        this->views->setCurrentWidget(this->dbint_w);
    });

    // view menu
    connect(ui->actionlight_theme, &QAction::triggered, this, [=](){
        this->setLightTheme();
    });
    connect(ui->actiondark_theme, &QAction::triggered, this, [=](){
        this->setDarkTheme();
    });
}

void MainWindow::setupMenuBar()
{
    this->themes_menu = new QActionGroup(this);
    this->themes_menu->setExclusive(true);
    this->themes_menu->addAction(ui->actiondark_theme);
    this->themes_menu->addAction(ui->actionlight_theme);

    ui->actionlight_theme->setCheckable(true);
    ui->actiondark_theme->setCheckable(true);

    this->setLightTheme();
}

void MainWindow::setLightTheme()
{
    ui->actionlight_theme->setChecked(true);

    QFile style(QSS_L_MAIN_PATH);
    style.open(QFile::ReadOnly);
    QString qss = style.readAll();
    this->setStyleSheet(qss);

    style.close();
}

void MainWindow::setDarkTheme()
{
    ui->actiondark_theme->setChecked(true);

    QFile style(QSS_D_MAIN_PATH);
    style.open(QFile::ReadOnly);
    QString qss = style.readAll();
    this->setStyleSheet(qss);

    style.close();
}
