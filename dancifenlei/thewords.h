#ifndef THEWORDS_H
#define THEWORDS_H

#include <QWidget>

namespace Ui {
class TheWords;
}

class TheWords : public QWidget
{
    Q_OBJECT

public:
    explicit TheWords(QWidget *parent = 0);
    friend class xiugai_gjz;
    ~TheWords();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TheWords *ui;
};

#endif // THEWORDS_H
