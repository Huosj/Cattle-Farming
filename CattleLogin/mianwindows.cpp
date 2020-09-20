#include "mianwindows.h"
#include "ui_mianwindows.h"

mianwindows::mianwindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mianwindows)
{
    ui->setupUi(this);
    this->setFixedSize(840,480);

    lab1.setParent(this);       //主标题
    lab1.setText("南理牛圈");
    tlef.setFamily("仿宋");
    tlef.setPointSize(35);
    tlef.setWeight(75);
    lab1.setFont(tlef);
    tlec.setColor(QPalette::WindowText,Qt::blue);
    lab1.setPalette(tlec);
    lab1.move(300,0);

    lab2.setParent(this);       //副标题
    lab2.setFrameStyle(2);
    lab2.setText(" 用户9191068407，欢迎登录！");
    lab2.resize(900,30);
    lab2.move(-10,65);


    btn1.setParent(this);       //按钮
    btn2.setParent(this);
    btn3.setParent(this);
    btn4.setParent(this);
    btn1.resize(250,80);
    btn2.resize(250,80);
    btn3.resize(250,80);
    btn4.resize(250,80);
    btn1.move(50,110);
    btn1.setText("牛圈管理");
    btn2.move(50,200);
    btn2.setText("库存管理");
    btn3.move(50,290);
    btn3.setText("市场管理");
    btn4.move(50,380);
    btn4.setText("牛牛医院");

    ui->calendarWidget->resize(480,350);        //日历
    ui->calendarWidget->move(320,110);

    connect(&btn1,&QPushButton::pressed,[=](){       //按钮操作
        qDebug()<<"牛圈管理";   //测试用例


    });


    connect(&btn2,&QPushButton::pressed,[=](){
        qDebug()<<"库存管理";   //测试用例


    });


    connect(&btn3,&QPushButton::pressed,[=](){
        qDebug()<<"市场管理";   //测试用例


    });


    connect(&btn4,&QPushButton::pressed,[=](){
        qDebug()<<"牛牛医院";   //测试用例


    });


}

mianwindows::~mianwindows()
{
    delete ui;
}
