#ifndef WORDS_H
#define WORDS_H

#include <QWidget>

namespace Ui {
class Words;
}

class Words : public QWidget
{
    Q_OBJECT

public:
    explicit Words(QWidget *parent = 0);
    friend class Dialog_xiugai;
    ~Words();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Words *ui;
};

#endif // WORDS_H
