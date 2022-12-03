#include "dfa.h"
#include "ui_dfa.h"
#include <QPainter>
#include <QDebug>
#include <QSqlQuery>
#include <math.h>
#include <QTime>
bool DFA::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->label && event->type() == QEvent::Paint)
    {
        magicTime();
    }
    if(change==0)
        magicTime();
    else
        magicTime1();
    return QWidget::eventFilter(watched,event);
}
void CalcVertexes(double startX, double startY, double endX, double endY, double& x1, double& y1, double& x2, double& y2)
{
    /*
     * @brief 求得箭头两点坐标
     */

    double arrowLength = 10;      // 箭头长度，一般固定
    double arrowDegrees = 0.5;    // 箭头角度，一般固定

    // 求 y / x 的反正切值
    double angle = atan2(endY - startY, endX - startX) + 3.1415926;

    // 求得箭头点 1 的坐标
    x1 = endX + arrowLength * cos(angle - arrowDegrees);
    y1 = endY + arrowLength * sin(angle - arrowDegrees);

    // 求得箭头点 2 的坐标
    x2 = endX + arrowLength * cos(angle + arrowDegrees);
    y2 = endY + arrowLength * sin(angle + arrowDegrees);
}
void DFA::magicTime()
{

    QPen pen;
    pen.setWidth(2);
    QPainter painter(ui->label);
    pen.setColor(Qt::red);
    //1.画箭头1
    painter.setPen(pen);
    int lineHStartPos; // 连接线起点水平位置
    int lineVStartPos; // 连接线起点垂直位置
    int lineHEndPos;   // 连接线终点水平位置
    int lineVEndPos;   // 连接线终点垂直位置
    lineHStartPos = 20;
    lineVStartPos = 45;
    lineHEndPos = 50;
    lineVEndPos = 45;
    QLineF line1(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line1);
    double x1, y1, x2, y2;// 箭头的两点坐标
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2); // 求得箭头两点坐标
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //1.2画圆
    QRectF rectangle1(55, 25.0, 40.0, 40.0);
    painter.drawEllipse(rectangle1);
    //1.3画箭头
    lineHStartPos = 100;
    lineVStartPos = 45;
    lineHEndPos = 155;
    lineVEndPos = 45;
    QLineF line2(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line2);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //1.4画圆
    QRectF rectangle2(160, 25.0, 40.0, 40.0);
    painter.drawEllipse(rectangle2);
    //1.5画箭头
    lineHStartPos = 197;
    lineVStartPos = 20;
    lineHEndPos = 197;
    lineVEndPos = 25;
    QLineF line3(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line3);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //1.6画圆弧
    painter.drawArc(163,5,35,35,100,2800);
    //1.7画竖直线
    QLineF line4(75.0, 70.0, 75.0, 500.0);
    painter.drawLine(line4);
    //1.8画横线（无符号整数）
    QLineF line31(210, 45.0, 370.0, 45.0);
    painter.drawLine(line31);
    //2.1画箭头
    lineHStartPos = 80;
    lineVStartPos = 115;
    lineHEndPos = 155;
    lineVEndPos = 115;
    QLineF line5(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line5);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //2.2画圆
    QRectF rectangle3(160, 95.0, 40.0, 40.0);
    painter.drawEllipse(rectangle3);
    //2.3画箭头
    lineHStartPos = 197;
    lineVStartPos = 85;
    lineHEndPos = 197;
    lineVEndPos = 90;
    QLineF line6(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line6);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //2.4画圆弧
    painter.drawArc(163,70,35,35,100,2800);
    //2.画线5
    QLineF line7(205.0, 115.0, 285.0, 115.0);
    painter.drawLine(line7);
    //2.画线6
    QLineF line8(290.0, 90.0, 290, 140);
    painter.drawLine(line8);
    //2.画箭头7
    lineHStartPos = 290;
    lineVStartPos = 90;
    lineHEndPos = 370;
    lineVEndPos = 90;
    QLineF line9(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line9);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //2.画箭头8
    lineHStartPos = 290;
    lineVStartPos = 140;
    lineHEndPos = 370;
    lineVEndPos = 140;
    QLineF line10(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line10);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //3.1画箭头
    lineHStartPos = 80;
    lineVStartPos = 180;
    lineHEndPos = 370;
    lineVEndPos = 180;
    QLineF line11(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line11);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //4.1画箭头
    lineHStartPos = 80;
    lineVStartPos = 245;
    lineHEndPos = 140;
    lineVEndPos = 245;
    QLineF line12(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line12);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //4.2画圆
    QRectF rectangle4(145, 225.0, 40.0, 40.0);
    painter.drawEllipse(rectangle4);
    //4.3画箭头
    lineHStartPos = 190;
    lineVStartPos = 245;
    lineHEndPos = 250;
    lineVEndPos = 245;
    QLineF line13(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line13);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //4.4画圆
    QRectF rectangle5(255, 225.0, 40.0, 40.0);
    painter.drawEllipse(rectangle5);
    //4.5画箭头
    lineHStartPos = 300;
    lineVStartPos = 245;
    lineHEndPos = 370;
    lineVEndPos = 245;
    QLineF line14(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line14);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //3.5.2画箭头
    lineHStartPos = 165;
    lineVStartPos = 210;
    lineHEndPos = 370;
    lineVEndPos = 210;
    QLineF line15(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line15);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //3.5.1画线
    QLineF line16(165, 210, 165, 220);
    painter.drawLine(line16);
    //5.1画箭头
    lineHStartPos = 80;
    lineVStartPos = 315;
    lineHEndPos = 140;
    lineVEndPos = 315;
    QLineF line17(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line17);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //5.2画圆
    QRectF rectangle6(145, 295.0, 40.0, 40.0);
    painter.drawEllipse(rectangle6);
    //5.3画箭头
    lineHStartPos = 190;
    lineVStartPos = 315;
    lineHEndPos = 250;
    lineVEndPos = 315;
    QLineF line18(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line18);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //5.4画圆
    QRectF rectangle7(255, 295.0, 40.0, 40.0);
    painter.drawEllipse(rectangle7);
    //5.5画箭头
    lineHStartPos = 300;
    lineVStartPos = 315;
    lineHEndPos = 370;
    lineVEndPos = 315;
    QLineF line19(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line19);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //5.3画箭头
    lineHStartPos = 185;
    lineVStartPos = 285;
    lineHEndPos = 185;
    lineVEndPos = 290;
    QLineF line29(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line29);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //5.4画圆弧
    painter.drawArc(150,270,35,35,100,2800);
    //5.5.2画箭头
    lineHStartPos = 165;
    lineVStartPos = 350;
    lineHEndPos = 370;
    lineVEndPos = 350;
    QLineF line27(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line27);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //5.5.1画线
    QLineF line28(165, 350, 165, 360);
    painter.drawLine(line28);
    //6.1画箭头
    lineHStartPos = 80;
    lineVStartPos = 385;
    lineHEndPos = 140;
    lineVEndPos = 385;
    QLineF line20(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line20);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //6.2画圆
    QRectF rectangle8(145, 365.0, 40.0, 40.0);
    painter.drawEllipse(rectangle8);
    //6.3画箭头
    lineHStartPos = 190;
    lineVStartPos = 385;
    lineHEndPos = 250;
    lineVEndPos = 385;
    QLineF line21(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line21);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //6.4画圆
    QRectF rectangle9(255, 365.0, 40.0, 40.0);
    painter.drawEllipse(rectangle9);
    //6.5画箭头
    lineHStartPos = 300;
    lineVStartPos = 385;
    lineHEndPos = 370;
    lineVEndPos = 385;
    QLineF line22(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line22);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //7.1画箭头
    lineHStartPos = 80;
    lineVStartPos = 455;
    lineHEndPos = 140;
    lineVEndPos = 455;
    QLineF line23(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line23);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //7.2画圆
    QRectF rectangle10(145, 435.0, 40.0, 40.0);
    painter.drawEllipse(rectangle10);
    //7.3画箭头
    lineHStartPos = 190;
    lineVStartPos = 455;
    lineHEndPos = 250;
    lineVEndPos = 455;
    QLineF line24(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line24);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //7.4画圆
    QRectF rectangle11(255, 435.0, 40.0, 40.0);
    painter.drawEllipse(rectangle11);
    //7.5画箭头
    lineHStartPos = 300;
    lineVStartPos = 455;
    lineHEndPos = 370;
    lineVEndPos = 455;
    QLineF line25(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line25);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //7.3画箭头
    lineHStartPos = 185;
    lineVStartPos = 425;
    lineHEndPos = 185;
    lineVEndPos = 430;
    QLineF line30(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line30);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //7.4画圆弧
    painter.drawArc(150,410,35,35,100,2800);
    //8.1画箭头
    lineHStartPos = 75;
    lineVStartPos = 500;
    lineHEndPos = 370;
    lineVEndPos = 500;
    QLineF line26(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line26);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //9.1画圆
    QRectF rectangle12(350, 520.0, 40.0, 40.0);
    painter.drawEllipse(rectangle12);
    //10.1画右边的竖线
    QLineF line32(370, 45, 370, 90);
    painter.drawLine(line32);
    //10.2画右边的竖线
    QLineF line33(370, 90, 370, 140);
    painter.drawLine(line33);
    //10.3画右边的竖线
    QLineF line34(370, 140, 370, 180);
    painter.drawLine(line34);
    //10.4画右边的竖线
    QLineF line35(370, 180, 370, 210);
    painter.drawLine(line35);
    //10.5画右边的竖线
    QLineF line36(370, 210, 370, 245);
    painter.drawLine(line36);
    //10.6画右边的竖线
    QLineF line37(370, 245, 370, 315);
    painter.drawLine(line37);
    //10.7画右边的竖线
    QLineF line38(370, 315, 370, 350);
    painter.drawLine(line38);
    //10.8画右边的竖线
    QLineF line39(370, 350, 370, 385);
    painter.drawLine(line39);
    //10.9画右边的竖线
    QLineF line40(370, 385, 370, 455);
    painter.drawLine(line40);
    //10.10画右边的竖线
    QLineF line41(370, 455, 370, 500);
    painter.drawLine(line41);
    //10.11画右边的箭头
    lineHStartPos = 370;
    lineVStartPos = 500;
    lineHEndPos = 370;
    lineVEndPos = 520;
    QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
    painter.drawLine(line42);
    CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
    painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
    painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
    //1.写字：
    painter.setFont(QFont("Arial", 8));
    painter.drawText(70,50,tr("S"));
    painter.drawText(110,35,tr("数字"));
    painter.drawText(210,25,tr("数字"));
    //2.
    painter.drawText(290,35,tr("无符号整数"));
    painter.drawText(110,105,tr("字母"));
    painter.drawText(210,75,tr("字母，数字"));
    painter.drawText(230,105,tr("LookUp"));
    painter.drawText(315,85,tr("标识符"));
    painter.drawText(315,135,tr("关键字"));
    //3.
    painter.drawText(90,175,tr("+ , - , * , / , ( , ) , ; , [ , ] , = , < "));
    painter.drawText(305,175,tr("单分界符"));
    //4.
    painter.drawText(170,205,tr("其他符号"));
    painter.drawText(305,205,tr("单分界符"));
    painter.drawText(100,235,tr("："));
    painter.drawText(220,235,tr("="));
    painter.drawText(305,235,tr("双分界符"));
    //5.
    painter.drawText(180,275,tr("其他符号"));
    painter.drawText(100,305,tr("{"));
    painter.drawText(220,305,tr("}"));
    painter.drawText(335,305,tr("注释"));
    //6.
    painter.drawText(180,345,tr("其他符号"));
    painter.drawText(100,375,tr("."));
    painter.drawText(220,375,tr("."));
    painter.setFont(QFont("Arial", 6));
    painter.drawText(285,375,tr("数组下标界限符"));
    painter.setFont(QFont("Arial", 8));
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.setFont(QFont("Arial", 6));
    painter.drawText(290,345,tr("程序结束标识"));
    painter.drawText(330,495,tr("报错"));
    //7.
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.setFont(QFont("Arial", 8));
    painter.drawText(180,415,tr("其他符号"));
    painter.drawText(100,445,tr("'"));
    painter.drawText(220,445,tr("'"));
    painter.setFont(QFont("Arial", 6));
    painter.drawText(295,445,tr("字符串标识符"));
    //8.
    painter.setFont(QFont("Arial", 8));
    painter.drawText(80,495,tr("其他符号"));
    //9.
    painter.drawText(365,545,tr("Z"));
}

//repaint
void DFA::magicTime1()
{
    QPen pen;
    pen.setWidth(2);
    QPainter painter(ui->label);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    int lineHStartPos; // 连接线起点水平位置
    int lineVStartPos; // 连接线起点垂直位置
    int lineHEndPos;   // 连接线终点水平位置
    int lineVEndPos;   // 连接线终点垂直位置
    double x1, y1, x2, y2;// 箭头的两点坐标
    switch (change) {
    case 1:{//无符号整数
        lineHStartPos = 100;
        lineVStartPos = 45;
        lineHEndPos = 155;
        lineVEndPos = 45;
        QLineF line2(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line2);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line31(210, 45.0, 370.0, 45.0);
        painter.drawLine(line31);
        QLineF line32(370, 45, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        painter.setFont(QFont("Arial", 8));
        painter.drawText(110,35,tr("数字"));
        painter.drawText(210,25,tr("数字"));
        painter.drawText(290,35,tr("无符号整数"));}
        break;
    case 2:{
        QLineF line4(75.0, 70.0, 75.0, 115.0);
        painter.drawLine(line4);
        lineHStartPos = 80;
        lineVStartPos = 115;
        lineHEndPos = 155;
        lineVEndPos = 115;
        QLineF line5(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line5);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line7(205.0, 115.0, 285.0, 115.0);
        painter.drawLine(line7);
        lineHStartPos = 290;
        lineVStartPos = 90;
        lineHEndPos = 370;
        lineVEndPos = 90;
        QLineF line9(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line9);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line32(370, 90, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line8(290.0, 90.0, 290, 115);
        painter.drawLine(line8);
        painter.setFont(QFont("Arial", 8));
        painter.drawText(110,105,tr("字母"));
        painter.drawText(210,75,tr("字母，数字"));
        painter.drawText(230,105,tr("LookUp"));
        painter.drawText(315,85,tr("标识符"));}
        break;
    case 3:{
        QLineF line8(290.0, 115.0, 290, 140);
        painter.drawLine(line8);
        QLineF line4(75.0, 70.0, 75.0, 115.0);
        painter.drawLine(line4);
        lineHStartPos = 80;
        lineVStartPos = 115;
        lineHEndPos = 155;
        lineVEndPos = 115;
        QLineF line5(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line5);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line7(205.0, 115.0, 285.0, 115.0);
        painter.drawLine(line7);
        lineHStartPos = 290;
        lineVStartPos = 90;
        lineHEndPos = 370;
        lineVEndPos = 90;
        lineHStartPos = 290;
        lineVStartPos = 140;
        lineHEndPos = 370;
        lineVEndPos = 140;
        QLineF line10(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line10);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line32(370, 140, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        painter.setFont(QFont("Arial", 8));
        painter.drawText(110,105,tr("字母"));
        painter.drawText(210,75,tr("字母，数字"));
        painter.drawText(230,105,tr("LookUp"));
        painter.drawText(315,135,tr("关键字"));
        break;}
    case 4:{
        QLineF line4(75.0, 70.0, 75.0, 180.0);
        painter.drawLine(line4);
        lineHStartPos = 80;
        lineVStartPos = 180;
        lineHEndPos = 370;
        lineVEndPos = 180;
        QLineF line11(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line11);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line32(370, 180, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        break;}
    case 5:{
        QLineF line4(75.0, 70.0, 75.0, 245.0);
        painter.drawLine(line4);
        lineHStartPos = 80;
        lineVStartPos = 245;
        lineHEndPos = 140;
        lineVEndPos = 245;
        QLineF line12(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line12);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        lineHStartPos = 165;
        lineVStartPos = 210;
        lineHEndPos = 370;
        lineVEndPos = 210;
        QLineF line15(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line15);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        //3.5.1画线
        QLineF line16(165, 210, 165, 220);
        painter.drawLine(line16);
        QLineF line32(370, 210, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        painter.setFont(QFont("Arial", 8));
        painter.drawText(100,235,tr("："));
        painter.drawText(170,205,tr("其他符号"));
        painter.drawText(305,205,tr("单分界符"));
        break;}
    case 6:{
        QLineF line4(75.0, 70.0, 75.0, 245.0);
        painter.drawLine(line4);
        lineHStartPos = 80;
        lineVStartPos = 245;
        lineHEndPos = 140;
        lineVEndPos = 245;
        QLineF line12(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line12);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        lineHStartPos = 190;
        lineVStartPos = 245;
        lineHEndPos = 250;
        lineVEndPos = 245;
        QLineF line13(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line13);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        lineHStartPos = 300;
        lineVStartPos = 245;
        lineHEndPos = 370;
        lineVEndPos = 245;
        QLineF line14(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line14);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line32(370, 245, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        painter.setFont(QFont("Arial", 8));
        painter.drawText(100,235,tr("："));
        painter.drawText(220,235,tr("="));
        painter.drawText(305,235,tr("双分界符"));
        break;}
    case 7:{
        QLineF line4(75.0, 70.0, 75.0, 315.0);
        painter.drawLine(line4);
        lineHStartPos = 80;
        lineVStartPos = 315;
        lineHEndPos = 140;
        lineVEndPos = 315;
        QLineF line17(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line17);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        lineHStartPos = 190;
        lineVStartPos = 315;
        lineHEndPos = 250;
        lineVEndPos = 315;
        QLineF line18(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line18);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        lineHStartPos = 300;
        lineVStartPos = 315;
        lineHEndPos = 370;
        lineVEndPos = 315;
        QLineF line19(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line19);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line32(370, 315, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        painter.setFont(QFont("Arial", 8));
        painter.drawText(180,275,tr("其他符号"));
        painter.drawText(100,305,tr("{"));
        painter.drawText(220,305,tr("}"));
        painter.drawText(335,305,tr("注释"));
        break;}
    case 8:{
        QLineF line4(75.0, 70.0, 75.0, 385.0);
        painter.drawLine(line4);
        lineHStartPos = 80;
        lineVStartPos = 385;
        lineHEndPos = 140;
        lineVEndPos = 385;
        QLineF line20(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line20);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        lineHStartPos = 165;
        lineVStartPos = 350;
        lineHEndPos = 370;
        lineVEndPos = 350;
        QLineF line27(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line27);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        //5.5.1画线
        QLineF line28(165, 350, 165, 360);
        painter.drawLine(line28);
        QLineF line32(370, 350, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        painter.setFont(QFont("Arial", 8));
        painter.drawText(180,345,tr("其他符号"));
        painter.drawText(100,375,tr("."));
        painter.setFont(QFont("Arial", 6));
        painter.drawText(290,345,tr("程序结束标识"));
        break;}
    case 9:{
        QLineF line4(75.0, 70.0, 75.0, 385.0);
        painter.drawLine(line4);
        lineHStartPos = 80;
        lineVStartPos = 385;
        lineHEndPos = 140;
        lineVEndPos = 385;
        QLineF line20(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line20);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        lineHStartPos = 190;
        lineVStartPos = 385;
        lineHEndPos = 250;
        lineVEndPos = 385;
        QLineF line21(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line21);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        lineHStartPos = 300;
        lineVStartPos = 385;
        lineHEndPos = 370;
        lineVEndPos = 385;
        QLineF line22(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line22);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line32(370, 385, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        break;}
    case 10:{QLineF line4(75.0, 70.0, 75.0, 455.0);
        painter.drawLine(line4);
        lineHStartPos = 80;
        lineVStartPos = 455;
        lineHEndPos = 140;
        lineVEndPos = 455;
        QLineF line23(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line23);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        lineHStartPos = 190;
        lineVStartPos = 455;
        lineHEndPos = 250;
        lineVEndPos = 455;
        QLineF line24(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line24);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        lineHStartPos = 300;
        lineVStartPos = 455;
        lineHEndPos = 370;
        lineVEndPos = 455;
        QLineF line25(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line25);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line32(370, 455, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        break;}
    default:{
        QLineF line4(75.0, 70.0, 75.0, 500.0);
        painter.drawLine(line4);
        lineHStartPos = 75;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 500;
        QLineF line26(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line26);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        QLineF line32(370, 500, 370, 520);
        painter.drawLine(line32);
        lineHStartPos = 370;
        lineVStartPos = 500;
        lineHEndPos = 370;
        lineVEndPos = 520;
        QLineF line42(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos);
        painter.drawLine(line42);
        CalcVertexes(lineHStartPos, lineVStartPos, lineHEndPos, lineVEndPos, x1, y1, x2, y2);
        painter.drawLine(lineHEndPos, lineVEndPos, x1, y1); // 绘制箭头一半
        painter.drawLine(lineHEndPos, lineVEndPos, x2, y2); // 绘制箭头另一半
        painter.setFont(QFont("Arial", 8));
        painter.drawText(80,495,tr("其他符号"));
        painter.setFont(QFont("Arial", 6));
        painter.drawText(330,495,tr("报错"));
        break;}
    }
    change=0;
}

bool DFA::isKey(char s[],char key[][20])
{
    for(int i = 0; i<n;i++)
    {
        if(strcmp(s,key[i]) == 0)
        {
            return true;	//关键字的种别码依次为 begin=1,if=2,then=3,while=4,do=5,end=6即为 i+1 的值
        }
    }
    return false;
}
//判断是不是字母
bool DFA::isChar(char ch)
{
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
    return true;
    else return false;
}
//判断是不是数字
bool DFA::isNum(char ch)
{
    if(ch>='0' && ch<='9')
        return true;
    else
        return false;
}
//核心子程序
void DFA::scanner(QString &syn,unsigned int &p,char s[])
{
    int count = 0;
    syn="报错";
    if(s[p] == ' ')
    {
        p++;

    }
    //开头是字母
    if(isChar(s[p]))
    {
        while(isNum(s[p]) || isChar(s[p]))
        {
            token[count++] = s[p];
            p++;
        }
        token[count] = '\0';	//'\0'作为结束符 ,将单词分隔开
        if(isKey(token,key)){
            syn="关键字";
            change=3;
        }
        else{
            syn="标识符";
            change=2;
        }
    }
    //开头是数字
    else if(isNum(s[p]))
    {
        while(isNum(s[p]))
        {
            token[count++] = s[p];
            p++;
        }
        token[count] = '\0';//结束标识
        syn = "无符号整数";	//数字digit(digit) *
        change=1;
    }
    //如果是运算符或者界符
    else
    {
        //先处理没有争议的字符
        switch(s[p])
        {
            case '+': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
            case '-': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
            case '*': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
            case '/': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
            case '=': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
            case ';': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
            case '(': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
            case ')': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
            case '[': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
            case ']': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
            case '<': syn = "单字符分界符";token[0] = s[p];token[1]='\0';break;
        }
        change=4;
        //处理有争议的
        //: :=
        if(s[p] == ':')
        {
            token[count++] = s[p];
            if(s[p+1] == '=')
            {
                p++;
                token[count++] = s[p];
                syn = "双分界符";
                change=6;
            }
            else
            {
                syn = "单分界符";
                change=5;
            }
            token[count] = '\0';
        }
        if(s[p] == '{')
        {
            token[count++] = s[p];
            int i=1;
            while(s[p+i] != '}'){
                p++;
                token[count++] = s[p];
            }
            p++;
            token[count++] = s[p];
            syn = "注释";
            change=7;
            token[count] = '\0';
        }


        if(s[p] == '.')
        {
            token[count++] = s[p];
            if(s[p+1] == '.')
            {
                p++;
                token[count++] = s[p];
                syn = "数组下标界限符";
                change=9;
            }
            else
            {
                syn = "程序结束符";
                change=8;
            }
            token[count] = '\0';
        }
        if(s[p]=='\'')
        {
            token[count++] = s[p];
            int i=1;
            while(s[p+i] != '\''){
                p++;
                token[count++] = s[p];
            }
            p++;
            token[count++] = s[p];
            syn = "字符串标识符";
            change=10;
            token[count] = '\0';
        }
        //后移
        p++;	//判断运算符和界符的这部分由于指针 p 没有向后指，所以需要将指针 p 向后移一位
    }

}

DFA::DFA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DFA)
{   change=0;
    ui->setupUi(this);
    ui->label->installEventFilter(this);
}
DFA::~DFA()
{
    delete ui;
}
void sleep(int m)
{
    QTime t;
    t.start();
    while(t.elapsed()<m)//1000ms = 1s
            QCoreApplication::processEvents();
}

void DFA::judge(char str1[]){
    unsigned int r=0;
    while(r < strlen(str1))	//循环条件 ,p还未指到字符串最后
    {   repaint();
        scanner(syn,r,str1);
        QString ln=QString::number(linenum);
        QString tk=QString::fromUtf8(token);
        ui->textEdit_2->insertPlainText('<'+ln+","+tk+','+syn+'>'+'\n');
        if(syn=="报错")
            change=11;
        repaint();
        sleep(2000);
        if(syn=="报错"||syn=="程序结束符"){
            break;
        }
    }
}

void DFA::input(char s[]){
    int p = 0;
    int q = 0;
    while(s[q]!='\0')
    {
       char str1[50]={0};
       for(int i=0;s[p]!=' '&&s[p]!='\0'&&s[p]!='\n'&&s[p]!='\t';i++){
           str1[i]=s[p];
           p++;
       }
       judge(str1);
       while(s[p]=='\n'){
            linenum++;
             p++;
       }
       while(s[p]==' '||s[p]=='\t'){
           p++;
       }
        q=p;
    }

}


void DFA::on_pushButton_clicked()
{
    QString s1;
    char *name;
    linenum=1;
    int i=0;
    QSqlQuery query1;
    QString str=QString("select * from guanjianzi;");
    query1.exec(str);
    while (query1.next())
    {
        str = query1.value(0).toString();
        QByteArray ba = str.toLatin1();
        name=ba.data();
        strcpy(key[i],name);
        i++;
    }
    n=i;
    s1=ui->textEdit->toPlainText();
    QByteArray ba = s1.toLatin1();
    s=ba.data();
    input(s);
}
