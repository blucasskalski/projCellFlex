#include "manuel.h"
#include <time.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    manuel w;
    w.show();


       qDebug() <<"Application créée par Alexandre Dubois en 2015 au cours du projet de la 2ème année de BTS IRIS.";

    return a.exec();



}
