#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include "mainwindowmenu.h"
#include "ui_mainwindowmenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MainWindowmenu *w1=new MainWindowmenu();
    w1->setWindowTitle("词法分析器");
    w1->show();
    this->close();
}
