#include "cifaguize.h"
#include "ui_cifaguize.h"

cifaguize::cifaguize(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cifaguize)
{
    ui->setupUi(this);
}

cifaguize::~cifaguize()
{
    delete ui;
}
