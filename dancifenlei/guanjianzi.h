#ifndef GUANJIANZI_H
#define GUANJIANZI_H
#include <QString>

class GuanJianZi
{
public:
    GuanJianZi();
    bool search(QString word);
    void change(QString charbefore,QString charnext);
    void add(QString word);
    ~GuanJianZi();
};

#endif // GUANJIANZI_H
