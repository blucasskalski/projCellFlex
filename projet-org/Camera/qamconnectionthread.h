/*#ifndef QAMCONNECTIONTHREAD_H
#define QAMCONNECTIONTHREAD_H

#include <QThread>
#include <QTcpSocket>


class QamConnectionThread : public QThread
{
    Q_OBJECT

public:
    explicit QamConnectionThread(qintptr id, QObject *parent = 0);
    void run();

signals:
     void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket* m_socket;
    qintptr     m_socketDescriptor;

};

#endif // QAMCONNECTIONTHREAD_H
*/
