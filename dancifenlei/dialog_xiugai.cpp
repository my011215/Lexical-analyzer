#include "dialog_xiugai.h"
#include "ui_dialog_xiugai.h"
#include "zifu.h"
#include <QString>
#include <QSqlTableModel>
Dialog_xiugai::Dialog_xiugai(QString word1,Words *w,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_xiugai)
{
    wordbefore=word1;
    wordnext="";
    w0=w;
    ui->setupUi(this);
}

Dialog_xiugai::~Dialog_xiugai()
{
    delete ui;
}

void Dialog_xiugai::on_pushButton_clicked()
{
    QString wordnext = ui->lineEdit->text();
    ZiFU *x=new ZiFU();
    x->change(wordbefore,wordnext);
    QSqlTableModel * model = new QSqlTableModel(w0->ui->tableView);
    model->setTable("zifubiao");//选择表
    model->select();
    w0->ui->tableView->setModel(model);
    w0->ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->close();
}

void Dialog_xiugai::on_pushButton_2_clicked()
{
    this->close();
}
