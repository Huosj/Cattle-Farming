#ifndef MIANWINDOWS_H
#define MIANWINDOWS_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPalette>
#include <QFont>
#include <QDebug>

namespace Ui {
class mianwindows;
}

class mianwindows : public QWidget
{
    Q_OBJECT

public:
    explicit mianwindows(QWidget *parent = 0);
    ~mianwindows();

private:
    Ui::mianwindows *ui;
    QLabel lab1;        //主标题
    QLabel lab2;        //副标题
    QPalette tlec;      //上色
    QFont tlef;         //设置字体、颜色、大小
    QPushButton btn1;   //牛圈管理
    QPushButton btn2;   //库存管理
    QPushButton btn3;   //市场管理
    QPushButton btn4;   //牛牛医院


};

#endif // MIANWINDOWS_H
