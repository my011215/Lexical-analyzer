#ifndef XIUGAI_GJZ_H
#define XIUGAI_GJZ_H

#include <QWidget>
#include "thewords.h"
#include "ui_thewords.h"
namespace Ui {
class xiugai_gjz;
}

class xiugai_gjz : public QWidget
{
    Q_OBJECT

public:
    explicit xiugai_gjz(QString word1,TheWords *w,QWidget *parent = 0);
    ~xiugai_gjz();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::xiugai_gjz *ui;
    QString wordbefore;
    QString wordnext;
    TheWords *w0;
};

#endif // XIUGAI_GJZ_H
