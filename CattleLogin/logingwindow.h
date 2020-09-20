#ifndef LOGINGWINDOW_H
#define LOGINGWINDOW_H

#include <QMainWindow>
#include <QLabel>       //
#include <QPushButton>  //
#include <QLineEdit>    //
#include <QString>
#include <QDebug>
#include <QPalette>
#include "mianwindows.h"

namespace Ui {
class logingwindow;
}

class logingwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit logingwindow(QWidget *parent = 0);
    ~logingwindow();

private:
    Ui::logingwindow *ui;
    QPushButton btn1;   //登录按钮
    QPushButton btn2;   //退出按钮
    QLineEdit xet1;     //用户名输入框
    QLineEdit xet2;     //密码输入框
    QLabel lab1;        //"用户名："
    QLabel lab2;        //"密码："
    QLabel lab3;        //"密码或用户名错误，请重新输入"
    QPalette warning1;  //给上面那句话上色
    mianwindows system_win; //定义主窗口
};


#endif // LOGINGWINDOW_H
