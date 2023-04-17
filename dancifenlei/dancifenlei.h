#ifndef DANCIFENLEI_H
#define DANCIFENLEI_H

#include <QWidget>

namespace Ui {
class dancifenlei;
}

class dancifenlei : public QWidget
{
    Q_OBJECT

public:
    explicit dancifenlei(QWidget *parent = 0);
    ~dancifenlei();

private:
    Ui::dancifenlei *ui;
};

#endif // DANCIFENLEI_H
