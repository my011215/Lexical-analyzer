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
#include <QByteArray>
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));    //若英文系统，则用GBK
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("bianyiyuanli");
    db.setUserName("root");
    db.setPassword("123456");
    //测试数据库是否连接
    bool ok = db.open();
    if (!ok){
        QMessageBox::information(&w, "infor", "open failed");
    }

    return a.exec();
}
