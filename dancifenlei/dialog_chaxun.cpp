#include "dialog_chaxun.h"
#include "ui_dialog_chaxun.h"

Dialog_chaxun::Dialog_chaxun(bool flag,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_chaxun)
{
    ui->setupUi(this);
    if(flag==true){
        ui->label->setText("查询成功");
    }
    else{
        ui->label->setText("未找到！");
    }
}

Dialog_chaxun::~Dialog_chaxun()
{
    delete ui;
}
