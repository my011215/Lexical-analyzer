#ifndef MAINWINDOWMENU_H
#define MAINWINDOWMENU_H

#include <QMainWindow>

namespace Ui {
class MainWindowmenu;
}

class MainWindowmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowmenu(QWidget *parent = 0);
    ~MainWindowmenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindowmenu *ui;
};

#endif // MAINWINDOWMENU_H
