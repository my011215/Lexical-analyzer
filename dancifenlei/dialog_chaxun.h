#ifndef DIALOG_CHAXUN_H
#define DIALOG_CHAXUN_H

#include <QDialog>

namespace Ui {
class Dialog_chaxun;
}

class Dialog_chaxun : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_chaxun(bool flag,QWidget *parent = 0);
    ~Dialog_chaxun();

private:
    Ui::Dialog_chaxun *ui;
};

#endif // DIALOG_CHAXUN_H
