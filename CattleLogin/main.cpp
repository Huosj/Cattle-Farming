#include "logingwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    logingwindow w;
    w.show();

    return a.exec();
}
