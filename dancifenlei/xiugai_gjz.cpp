#include "xiugai_gjz.h"
#include "ui_xiugai_gjz.h"
#include "guanjianzi.h"
#include <QString>
#include <QSqlTableModel>
xiugai_gjz::xiugai_gjz(QString word1,TheWords *w,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xiugai_gjz)
{
    wordbefore=word1;
    wordnext="";
    w0=w;
    ui->setupUi(this);
}

xiugai_gjz::~xiugai_gjz()
{
    delete ui;
}

void xiugai_gjz::on_pushButton_clicked()
{
    QString wordnext = ui->lineEdit->text();
    GuanJianZi *x=new GuanJianZi();
    x->change(wordbefore,wordnext);
    QSqlTableModel * model = new QSqlTableModel(w0->ui->tableView);
    model->setTable("guanjianzi");//选择表
    model->select();
    w0->ui->tableView->setModel(model);
    w0->ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->close();
}

void xiugai_gjz::on_pushButton_2_clicked()
{
    this->close();
}
