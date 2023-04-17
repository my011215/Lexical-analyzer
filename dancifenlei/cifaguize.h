#ifndef CIFAGUIZE_H
#define CIFAGUIZE_H

#include <QWidget>

namespace Ui {
class cifaguize;
}

class cifaguize : public QWidget
{
    Q_OBJECT

public:
    explicit cifaguize(QWidget *parent = 0);
    ~cifaguize();

private:
    Ui::cifaguize *ui;
};

#endif // CIFAGUIZE_H
