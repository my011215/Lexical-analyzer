#include "dancifenlei.h"
#include "ui_dancifenlei.h"

dancifenlei::dancifenlei(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dancifenlei)
{
    ui->setupUi(this);
}

dancifenlei::~dancifenlei()
{
    delete ui;
}
