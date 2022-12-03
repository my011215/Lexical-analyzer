#ifndef DFA_H
#define DFA_H

#include <QWidget>

namespace Ui {
class DFA;
}

class DFA : public QWidget
{
    Q_OBJECT

public:
    explicit DFA(QWidget *parent = 0);
    bool eventFilter(QObject *watched, QEvent *event);
    void magicTime();
    void magicTime1();
    bool isKey(char s[],char key[][20]);
    bool isChar(char ch);
    bool isNum(char ch);
    void input(char s[]);
    void scanner(QString &syn,unsigned int &p,char s[]);
    void judge(char str1[]);
    ~DFA();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DFA *ui;
    char key[50][20];
    char *s;
    char token[40];
    int linenum;
    int change;
    int n;
    QString syn;
};

#endif // DFA_H
