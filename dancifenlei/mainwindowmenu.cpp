#include "mainwindowmenu.h"
#include "ui_mainwindowmenu.h"
#include "words.h"
#include "dfa.h"
#include "ui_dfa.h"
#include "thewords.h"
#include "dancifenlei.h"
#include "ui_dancifenlei.h"
#include "danzifufjf.h"
#include "ui_danzifufjf.h"
#include "staticdfa.h"
#include "ui_staticdfa.h"
#include "cifaguize.h"
#include "ui_cifaguize.h"
MainWindowmenu::MainWindowmenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowmenu)
{

    ui->setupUi(this);
}

MainWindowmenu::~MainWindowmenu()
{
    delete ui;
}

void MainWindowmenu::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindowmenu::on_pushButton_5_clicked()
{
    Words *m1=new Words();
    m1->setWindowTitle("字符表");
    m1->show();
}

void MainWindowmenu::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindowmenu::on_pushButton_9_clicked()
{
    danzifuFJF *w1=new danzifuFJF();
    w1->setWindowTitle("单字符分界符");
    w1->show();
}

void MainWindowmenu::on_pushButton_11_clicked()
{
    DFA *w1=new DFA();
    w1->setWindowTitle("词法分析器");
    w1->show();
}

void MainWindowmenu::on_pushButton_8_clicked()
{
    TheWords *w1=new TheWords();
    w1->setWindowTitle("关键字表");
    w1->show();
}

void MainWindowmenu::on_pushButton_6_clicked()
{
    dancifenlei *w1=new dancifenlei();
    w1->setWindowTitle("单词分类");
    w1->show();
}

void MainWindowmenu::on_pushButton_10_clicked()
{
    staticDFA *w1=new staticDFA();
    w1->setWindowTitle("单词扫描DFA");
    w1->show();
}

void MainWindowmenu::on_pushButton_7_clicked()
{
    cifaguize *w1=new cifaguize();
    w1->setWindowTitle("词法规则-巴科斯范式");
    w1->show();
}
