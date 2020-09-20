#include "logingwindow.h"
#include "ui_logingwindow.h"

logingwindow::logingwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logingwindow)
{
    ui->setupUi(this);
    this->setFixedSize(300,200);        //锁死窗口大小
    this->setWindowTitle("南里牛圈登录");
    btn1.setParent(this);
    btn2.setParent(this);
    xet1.setParent(this);
    xet2.setParent(this);
    lab1.setParent(this);
    lab2.setParent(this);
    lab3.setParent(this);
    btn1.resize(300,40);
    btn1.move(0,120);
    btn1.setText("登录");
    btn2.resize(300,40);
    btn2.move(0,160);
    btn2.setText("退出");
    connect(&btn2,&QPushButton::pressed,this,&QWidget::close);

    lab1.resize(60,40);     //字
    lab1.setText("用户名：");
    lab1.move(5,5);
    lab2.resize(60,40);
    lab2.setText("密码：");
    lab2.move(5,55);

    xet1.resize(230,30);        //输入框
    xet1.move(65,10);
    xet1.setPlaceholderText("请输入用户名");
    xet1.setText("9191068407");
    xet2.resize(230,30);
    xet2.move(65,60);
    xet2.setPlaceholderText("请输入密码");   //get新功能
    xet2.setEchoMode(QLineEdit::Password);

    lab3.resize(300,20);
    lab3.move(0,100);

    connect(&btn1,&QPushButton::pressed,[=](){      //按键操作
        if(xet1.text()=="9191068407"&&xet2.text()=="123456"){
            //qDebug()<<"登录成功"; //测试用例
            system_win.show();
            this->close();
        }
        else{
            lab3.setText("用户名或密码错误");
            warning1.setColor(QPalette::WindowText,Qt::red);
            lab3.setPalette(warning1);
        }
    });
}

logingwindow::~logingwindow()
{
    delete ui;
}
