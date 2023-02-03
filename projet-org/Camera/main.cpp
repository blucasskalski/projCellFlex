#include "camera.h"
#include "qamtcpserver.h"
#include <QApplication>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    camera cam;
    cam.resize(1280,1024);
    cam.show();
    return app.exec();
}
