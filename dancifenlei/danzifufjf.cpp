#include "danzifufjf.h"
#include "ui_danzifufjf.h"
#include <QString>
#include <QSqlTableModel>
danzifuFJF::danzifuFJF(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::danzifuFJF)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QSqlTableModel *model = new QSqlTableModel(ui->tableView);
    model->setTable("danzifufenjiefu");//选择表
    model->select();
    //把model放在view里面
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

danzifuFJF::~danzifuFJF()
{
    delete ui;
}
