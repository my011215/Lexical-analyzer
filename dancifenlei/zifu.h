#ifndef ZIFU_H
#define ZIFU_H
#include <QString>

class ZiFU
{
public:
    ZiFU();
    bool search(QString word);
    void change(QString charbefore,QString charnext);
    ~ZiFU();
};

#endif // ZIFU_H
