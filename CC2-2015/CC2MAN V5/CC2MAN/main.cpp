#include "manuel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    manuel w;
    w.show();

    return a.exec();


}
