#include "staticdfa.h"
#include "ui_staticdfa.h"

staticDFA::staticDFA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::staticDFA)
{
    ui->setupUi(this);
}

staticDFA::~staticDFA()
{
    delete ui;
}
