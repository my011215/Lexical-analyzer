#ifndef DIALOG_XIUGAI_H
#define DIALOG_XIUGAI_H

#include <QDialog>
#include "words.h"
#include "ui_words.h"

namespace Ui {
class Dialog_xiugai;
}

class Dialog_xiugai : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_xiugai(QString word1,Words *w,QWidget *parent = 0);
    ~Dialog_xiugai();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog_xiugai *ui;
    QString wordbefore;
    QString wordnext;
    Words *w0;
};

#endif // DIALOG_XIUGAI_H
