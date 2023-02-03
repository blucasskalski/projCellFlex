#include "connexion.h"

Connexion::Connexion(QObject *parent) :
    QThread(parent)
{



}


void Connexion::connection()
{
    ui->connexion->setEnabled(false);
    //Requête => l'url de la cameras
    QNetworkRequest requete(QUrl("http://root:iris@192.168.3.6/axis-cgi/jpg/image.cgi?resolution:640x480"));
    QNetworkAccessManager *m = new QNetworkAccessManager;

    // Télécharge le contenu de notre requête.
    QNetworkReply *r= m->get(requete);

    //Gestion du signal d'érreur
    connect(r, SIGNAL(error(QNetworkReply::NetworkError)), this,
        SLOT(erreurConnection(QNetworkReply::NetworkError)));

    connect(r,SIGNAL(finished()),this,SLOT(reponse_connexion()));

    communication(); //lancement du thread Modbus
    ui->config->setEnabled(true);
    ui->exit->setEnabled(true);
}
