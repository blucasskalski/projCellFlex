/*#include "qamconnectionthread.h"
#include "camera.h"

QamConnectionThread::QamConnectionThread(qintptr id, QObject *parent) :
    QThread(parent)
  ,m_socketDescriptor( id )
{
}

void QamConnectionThread::run()
{
    qDebug() << "Thread started...";
    m_socket = new QTcpSocket();
    if (!m_socket->setSocketDescriptor(m_socketDescriptor) ){
        emit error(m_socket->error() );
        return;
    }
    connect(m_socket, SIGNAL(readyRead() ),
            this, SLOT(readyRead()), Qt::DirectConnection);
    connect(m_socket, SIGNAL(disconnected()),
            this, SLOT(disconnected()) );
    qDebug() << "Client" << m_socketDescriptor << "connected";
    exec();
}
void QamConnectionThread::readyRead()
{
    QByteArray frame = m_socket->readAll();
    qDebug() << "client" << m_socketDescriptor << "data in:" << frame;

    if (frame == "1")
    {
        camera *toto  = new camera();

        toto->prendre_photo();

        delete toto;
    }

    //m_socket->write(frame.data());

}

void QamConnectionThread::disconnected()
{
    qDebug() << "Client" << m_socketDescriptor << "disconnected";
    m_socket->deleteLater();
    exit(0);
}*/
