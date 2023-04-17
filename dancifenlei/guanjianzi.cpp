#include "guanjianzi.h"
#include <QSqlQuery>
#include <QDebug>
GuanJianZi::GuanJianZi()
{

}
bool GuanJianZi::search(QString word)
{
    QSqlQuery query;
    QString str = QString("SELECT * FROM `guanjianzi` WHERE binary `keyword`='%1';").arg(word);
    query.exec(str);
    bool flag=false;
    while(query.next())
    {
        QString s=query.value(0).toString();
        if(s!=NULL)
            flag=true;

    }
    return flag;
}
void GuanJianZi::change(QString charbefore,QString charnext){
    QSqlQuery query;
    QString temp = QString("update guanjianzi set `keyword` = '%1'where `keyword` = '%2' limit 1").arg(charnext).arg(charbefore);
    query.exec(temp);
}
void GuanJianZi::add(QString word)
{
    QSqlQuery query;
    QString str = QString("insert into guanjianzi(`keyword`)values('%1')").arg(word);
    query.exec(str);
}
GuanJianZi::~GuanJianZi()
{

}

