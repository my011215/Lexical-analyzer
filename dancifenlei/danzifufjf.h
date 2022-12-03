#ifndef DANZIFUFJF_H
#define DANZIFUFJF_H

#include <QWidget>

namespace Ui {
class danzifuFJF;
}

class danzifuFJF : public QWidget
{
    Q_OBJECT

public:
    explicit danzifuFJF(QWidget *parent = 0);
    ~danzifuFJF();

private:
    Ui::danzifuFJF *ui;
};

#endif // DANZIFUFJF_H
