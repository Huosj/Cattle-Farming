#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QString>
#include <QPlainTextEdit>
int money=50000;
class feed{
    public:
        int price,addtoWeight,addtoMilkProduction,acceleratetoGrowthCycle;
        feed(int p,int aw,int am,int ag){
            price=p;
            //money-=price;
            addtoWeight=aw;
            addtoMilkProduction=am;
            acceleratetoGrowthCycle=ag;
        }
};

class cattle{
    protected:
        int price,weight,milkProduction,growthCycle;//价格 体重 产奶量 生长周期
    public:
        static int _num,sum_milkProduction;
        /*void _show(){
            multiprintf(" 价格：");
            cout<<price;
            multiprintf(" 体重：");
            cout<<weight;
            multiprintf(" 产奶量：");
            cout<<milkProduction;
            multiprintf(" 生长周期：");
            cout<<growthCycle<<endl;
        }*/
        cattle(int p=0,int w=0,int m=0,int g=0):price(p),weight(w),milkProduction(m),growthCycle(g){
            _num++;
            money-=price;
            sum_milkProduction+=milkProduction;
            //_show();
        }
        ~cattle(){
            //multiprintf("成功删除一头牛");
            _num--;
            sum_milkProduction-=milkProduction;
        }
        void operator+= (const feed &f);
};
int cattle::_num=0,cattle::sum_milkProduction=0;
class milkCattle:public cattle{
    public:
        static int num;
        void show(){
            //cattle::_show();
        }
        milkCattle(int p=1000,int w=800,int m=1200,int g=360):cattle(p,w,m,g){
            /*multiprintf("成功购入一头奶牛，当前共有");
            cout<<++num;
            multiprintf("头奶牛");
            show();*/
        };
        /*~milkCattle(){
            multiprintf("成功删除一头奶牛");//问题：以*cattle指针形式delete时不会调用派生类的析构函数
            show();
        }*/
};
int milkCattle::num=0;
class bigbeefCattle:public cattle{
    public:
        static int num;
        void show(){
            //multiprintf(" 购入一头大肉牛");
            //cattle::_show();
        }
        bigbeefCattle(int p=1400,int w=1200,int m=300,int g=450):cattle(p,w,m,g){
            /*multiprintf("成功购入一头大肉牛，当前共有");
            cout<<++num;
            multiprintf("头大肉牛");
            show();*/
        };
};
int bigbeefCattle::num=0;
class smallbeefCattle:public cattle{
    public:
        static int num;
        void show(){
            //multiprintf(" 购入一头小肉牛");
            //cattle::_show();
        }
        smallbeefCattle(int p=600,int w=600,int m=100,int g=270):cattle(p,w,m,g){
            /*multiprintf("成功购入一头小肉牛，当前共有");
            cout<<++num;
            multiprintf("头小肉牛");
            show();*/
        };

};
int smallbeefCattle::num=0;
class niujuan{
    protected:
        cattle herd[100];
    public:
        int count=0;
        void add(cattle *c){
            if(count<100) herd[count++]=*c;
        }
        void show(){
            for(int i=0;i<count;i++){
                //herd[i]._show();
            }
        }
};
/*class nainiujuan::public niujuan{

}
class rouniu::public niujuan*/

void cattle::operator+= (const feed &f){
    weight+=f.addtoWeight;
    milkProduction+=f.addtoMilkProduction;
    if(growthCycle>f.acceleratetoGrowthCycle) growthCycle-=f.acceleratetoGrowthCycle;
    else growthCycle=0;
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->show();


    {
    int day=0,a=0,b=0,c=0,milk=0,d=0,e=0,f=0,feedindex=0;
    cattle *Cattle[1000]={NULL};
    niujuan NJ[3];
    feed Feed_1(10,20,10,5),Feed_2(12,25,10,10),Feed_3(15,20,30,10);
    do{
        while(a--&&(cattle::_num<1000)) {
            Cattle[ cattle::_num ]=new milkCattle; //会先执行构造函数使得cattle::_num自增
            NJ[0].add(Cattle[cattle::_num]);
        }
        while(b--&&(cattle::_num<1000)) {
            Cattle[ cattle::_num ]=new bigbeefCattle;
            NJ[1].add(Cattle[cattle::_num]);
        }
        while(c--&&(cattle::_num<1000)) {
            Cattle[ cattle::_num ]=new smallbeefCattle;
            NJ[2].add(Cattle[cattle::_num]);
        }
        for(int i=0;i<3;i++) NJ[i].show();
        ui->cattleText->appendPlainText(QString("日期：第%1天 当前金额：%2 当日产奶量：%3 牧场鲜奶储备：%4").arg(QString::number(++day),QString::number(money),QString::number(cattle::sum_milkProduction),QString::number(milk+=cattle::sum_milkProduction)));


        /*if(day>1){
            multiprintf(" 输入计划购买饲料的编号(1、2、3；输入0以跳过；输入负数以退出)：\n");
            cin>>feedindex;
            if(feedindex<0) break;
            switch(feedindex){
                case 1:
                    for(int i=1;i<=cattle::_num;i++){
                        *Cattle[i]+=Feed_1;
                    }
                    break;
                case 2:
                    for(int i=1;i<=cattle::_num;i++){
                        *Cattle[i]+=Feed_2;
                    }
                    break;
                case 3:
                    for(int i=1;i<=cattle::_num;i++){
                        *Cattle[i]+=Feed_3;
                    }
                    break;
                default:break;
            }
        }*/ //饲料功能紧急开发中
        a=QInputDialog::getInt(this,QString("输入对话框"),QString("输入购入奶牛数量："),0,-1,50000,1);
        b=QInputDialog::getInt(this,QString("输入对话框"),QString("输入购入大肉牛数量："),0,-1,50000,1);
        c=QInputDialog::getInt(this,QString("输入对话框"),QString("输入购入小肉牛数量："),0,-1,50000,1);
    }while(a>=0&&b>=0&&c>=0);
    for(int i=1;i<=cattle::_num;i++){
        delete Cattle[i];
    }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
