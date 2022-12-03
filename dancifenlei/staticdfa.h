#ifndef STATICDFA_H
#define STATICDFA_H

#include <QWidget>

namespace Ui {
class staticDFA;
}

class staticDFA : public QWidget
{
    Q_OBJECT

public:
    explicit staticDFA(QWidget *parent = 0);
    ~staticDFA();

private:
    Ui::staticDFA *ui;
};

#endif // STATICDFA_H
