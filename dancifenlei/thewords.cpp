#include "thewords.h"
#include "ui_thewords.h"
#include "xiugai_gjz.h"
#include "ui_xiugai_gjz.h"
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
#include "guanjianzi.h"
#include "dialog_chaxun.h"
#include "ui_dialog_chaxun.h"
#include "dialog_xiugai.h"
#include "ui_dialog_xiugai.h"
#include <QMessageBox>
TheWords::TheWords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TheWords)
{
    ui->setupUi(this);
    QSqlTableModel *model = new QSqlTableModel(ui->tableView);
    model->setTable("guanjianzi");//选择表
    model->select();
    //把model放在view里面
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

TheWords::~TheWords()
{
    delete ui;
}

void TheWords::on_pushButton_clicked()
{
    QString word=ui->lineEdit->text();
    GuanJianZi *x=new GuanJianZi();
    bool flag=x->search(word);
    Dialog_chaxun *w1=new Dialog_chaxun(flag);
    w1->setWindowTitle("查询结果");
    w1->show();
}

void TheWords::on_pushButton_2_clicked()
{
    QString word = ui->lineEdit->text();
    xiugai_gjz *w1=new xiugai_gjz(word,this);
    w1->setWindowTitle("修改关键字");
    w1->show();
}

void TheWords::on_pushButton_4_clicked()
{
    QString word = ui->lineEdit->text();
    GuanJianZi *x=new GuanJianZi();
    bool flag=x->search(word);
    if(!flag){
        x->add(word);
        QMessageBox::information(this,"提示","添加成功！",QMessageBox::Yes);
    }
    else
        QMessageBox::critical(this,"提示","已添加过该关键字");
    QSqlTableModel *model = new QSqlTableModel(ui->tableView);
    model->setTable("guanjianzi");//选择表
    model->select();
    //把model放在view里面
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
