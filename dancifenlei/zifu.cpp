#include "zifu.h"
#include <QSqlQuery>
#include <QDebug>
ZiFU::ZiFU()
{

}
bool ZiFU::search(QString word)
{
    QSqlQuery query;
    QString str = QString("SELECT * FROM `zifubiao` WHERE binary `character`='%1';").arg(word);
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
void ZiFU::change(QString charbefore,QString charnext){
    QSqlQuery query;
    QString temp = QString("update zifubiao set `character` = '%1'where `character` = '%2' limit 1").arg(charnext).arg(charbefore);
    query.exec(temp);
}

ZiFU::~ZiFU()
{

}

