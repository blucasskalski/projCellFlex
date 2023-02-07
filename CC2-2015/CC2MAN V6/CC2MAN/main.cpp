#include "manuel.h"
#include "threadauto.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    manuel w;
    w.show();

       qDebug() <<"thread principal  :" << a.thread();




    return a.exec();


}
