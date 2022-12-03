#include "words.h"
#include "ui_words.h"
#include "zifu.h"
#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QMainWindow>
#include <QSqlQuery>
#include <QTextCodec>
#include <QTextStream>
#include <QtCore>
#include <QSqlTableModel>
#include "dialog_chaxun.h"
#include "ui_dialog_chaxun.h"
#include "dialog_xiugai.h"
#include "ui_dialog_xiugai.h"
Words::Words(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Words)
{
    ui->setupUi(this);
    QSqlTableModel *model = new QSqlTableModel(ui->tableView);
    model->setTable("zifubiao");//选择表
    model->select();
    //把model放在view里面
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Words::~Words()
{
    delete ui;
}

void Words::on_pushButton_clicked()
{
    QString word=ui->lineEdit->text();
    ZiFU *x=new ZiFU();
    bool flag=x->search(word);
    Dialog_chaxun *w1=new Dialog_chaxun(flag);
    w1->setWindowTitle("查询结果");
    w1->show();
}

void Words::on_pushButton_2_clicked()
{
    QString word = ui->lineEdit->text();
    Dialog_xiugai *w1=new Dialog_xiugai(word,this);
    w1->setWindowTitle("修改字符");
    w1->show();
}

void Words::on_pushButton_3_clicked()
{
    QSqlTableModel * model = new QSqlTableModel(ui->tableView);
    model->setTable("zifubiao");//选择表
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
