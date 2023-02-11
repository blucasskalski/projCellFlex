#include "camera.h"
#include "QDebug"

camera::camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::camera)
{
    ui->setupUi(this);

    reglage();

    ecrir_log("*****************************************************************************************************");
    ecrir_log("*\t\t\t\t\t\t                               *");
    ecrir_log("*\t*---\t        Poste Vison du projet Cellflex 2014 \t---*                          *");
    ecrir_log("*\t*---\t            Réalisé par NOTTET Alexandre    \t---*                          *");
    ecrir_log("*\t*---\t                    Version 1.0             \t\t---*                          *");
    ecrir_log("*\t\t\t\t\t\t                               *");
    ecrir_log("*****************************************************************************************************");
    ecrir_log("");

    ecrir_log("Démarrage du Poste Camera");

    connect(ui->photo,SIGNAL(clicked()), this, SLOT(traitement_photo()) );
    connect(ui->config,SIGNAL(clicked()), this,SLOT(config()));
    connect(ui->config,SIGNAL(clicked()), this, SLOT(message_photo()));
    connect(ui->save_config,SIGNAL(clicked()), this, SLOT(save_config()));
    connect(ui->automatique,SIGNAL(clicked(bool)), this, SLOT(reglage_button()));
    connect(ui->manuel,SIGNAL(clicked(bool)), this, SLOT(reglage_button()));

    //réglage des bin et blanc
    connect(ui->bin1,SIGNAL(valueChanged(int)), this, SLOT(valeur_bin1(int)) );
    connect(ui->bin2, SIGNAL(valueChanged(int)), this, SLOT(valeur_bin2(int)) );
    connect(ui->blanc1, SIGNAL(valueChanged(int)), this, SLOT(valeur_blanc1(int)) );
    connect(ui->blanc2, SIGNAL(valueChanged(int)), this, SLOT(valeur_blanc2(int)) );

    //cscene camera et scene traitement
    scene_cam = new Qamgraphicsscene(this);
    scene_config = new Qamgraphicsscene(this);
    scene_signature = new Qamgraphicsscene(this);
    scene_bin = new Qamgraphicsscene(this);
    traitement = new QamImgProcessor();
    histogramme = new QamImgHistogram(ui->histo);
    histogramme->resize(ui->histo->size());

    if(ui->automatique->isChecked())
    {
        ui->photo->setEnabled(false);
    }
    else if(!ui->automatique->isChecked())
    {
        ui->photo->setEnabled(true);
    }

    connect(scene_config, SIGNAL(mouseRect(int,int, int, int)), this, SLOT(mousepoint(int,int, int,int)));

    //création du serveur Modbus
    QString csv = "/home/cellflex-vision/Documents/projet/config/cellflex_vision.csv";
    ecrir_log("Chargement du CSV Modbus");

    //création de la map
    m_map = new QamModbusMap( QamModbusMap::ServerMode, this ) ;
    m_map->setVerbose( false ) ;
    m_map->loadMap( csv ) ;
    this->table = QamModbusMap::Coil;
    this->m_table_holding = QamModbusMap::HoldingRegister;

    // serveur TCP
    m_server = new QamTcpServer( m_map, this ) ;
    m_server->start( m_map->port());

    //thread
    attente = new Communication(this, m_map); //création de la thread
    connect(attente, SIGNAL(faire_traitement()), this, SLOT(traitement_photo()));
    connect(ui->exit,SIGNAL(clicked()), attente, SLOT(arret()));
    ecrir_log("Lancement du thread Modbus");

    connect(ui->connexion,SIGNAL(clicked()), this, SLOT(connection()) );
}

camera::~camera()
{
    delete m_map;
    delete m_server;
    delete attente;
    delete scene_cam;
    delete scene_config;
    delete m_server;
    delete pix;
    delete scene_bin;
    delete scene_signature;
    delete traitement;
    delete histogramme;
    delete ui;
}

// ------------------------------------------------------------------------
// Affichage de la photo
// ------------------------------------------------------------------------
void camera::affichage_image()
{
    if(!error)
      {
          pix = new QGraphicsPixmapItem((QPixmap::fromImage(image)));

          scene_cam->clear();
          scene_cam->addItem(pix);
          ui->fenetre->setScene(scene_cam);

          connection();
      }
}

// ------------------------------------------------------------------------
// Gestion de la conection TCP-Camera
// ------------------------------------------------------------------------
void camera::connection()
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
// ------------------------------------------------------------------------
// Requête
// ------------------------------------------------------------------------
void camera::reponse_connexion()
{
    /*Réponse du serveur*/
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());

    /*lecture de l'image reçus*/
    image.loadFromData(r->readAll());

    affichage_image();//affichange de l'image

    //nettoyage de la requète
    r->deleteLater(); //vide le replay
    r->manager()->deleteLater(); //vide le manager
}

// ------------------------------------------------------------------------
// Gestion des éventuelles érreures de connection
// ------------------------------------------------------------------------
void camera::erreurConnection(QNetworkReply::NetworkError)
{
    error = true;
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
    QMessageBox::critical(this, "Erreur", "Erreur lors de la lecture. Vérifiez votre connexion. <br /><br /> Code de l'erreur : <br /><em>" + r->errorString() + "</em>");
    attente->arret();
    close();
}

// ------------------------------------------------------------------------
// Affichage des traitements
// ------------------------------------------------------------------------
void camera::fenetre_1(QImage * photo)
{

    scene_bin->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(*photo)));
    ui->photo_size->setScene(scene_bin);
}
void camera::netoyage_bin()
{
    scene_bin->clear();
    delete ui->photo_size->scene();
    scene_bin = new QGraphicsScene(this);
}


void camera::fenetre_2(QImage * photo)
{

    scene_signature->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(*photo)));
    ui->photo_bin->setScene(scene_signature);
}
void camera::netoyage_signature()
{
    scene_signature->clear();
    delete ui->photo_bin->scene();
    scene_signature = new QGraphicsScene(this);
}

// ------------------------------------------------------------------------
// Traitement à effectuer sur la photo
// ------------------------------------------------------------------------
void camera::traitement_photo()
{
    netoyage_bin();
    netoyage_signature();
    QElapsedTimer time;
    if(!premier_passage)
    {
        time.start();
    }
    else
    {
        time.restart();
    }

    if(tempo == 0 || tempo == 1)  ecrir_log("");
    if(tempo == 0 || tempo == 1)  ecrir_log("Début traitement");


    piece = false;

    QImage * dest = new QImage(image);
    QImage * dest1 = new QImage (*dest);



    traitement->setSrcImage(dest);
    traitement->setDstImage(dest1);
    traitement->cut(position_x,position_y,position_w,position_h);// redimmention de l'image en fonction de la cam

    fenetre_1(dest1);
    histogramme->setImage(*dest1);

    QImage * dest2 = new QImage(*dest1);
    traitement->setSrcImage(dest1);
    traitement->setDstImage(dest2);
    traitement->size(300,300);

    traitement->setSrcImage(dest2);
    traitement->setDstImage(dest1);
    traitement->enhanceWhite(blanc1,blanc2);

    traitement->setSrcImage(dest1);
    traitement->setDstImage(dest2);
    densite_photo = traitement->binarization(bin1,bin2);
    tempo_densite = densite_photo;

    grid = traitement->grid(4);
    line_1 = traitement->line(1,1,99,99,50);
    line_2 = traitement->line(99,1,1,99,50);

    grid_AS = traitement->gridAsString(grid);
    line_AS1 = traitement->lineAsString(line_1);
    line_AS2 = traitement->lineAsString(line_2);
    fenetre_2(dest2);
    ecrir_log(grid_AS);
    ecrir_log(line_AS1);

    reconnaissance();

    if(piece == false && tempo < 2)
    {
        premier_passage = true;

        nouvelle_tentative();
        return;
    }

    temps = time.elapsed();
    envoie_donees();

    delete dest;
    delete dest1;
    delete dest2;
    tempo =0;
    ui->photo->setEnabled(true);
    premier_passage = false;

}

void camera::reconnaissance()
{
    QFile file("/home/cellflex-vision/Documents/projet/config/BDD.csv");
    if(tempo == 0 || tempo == 1)  ecrir_log("chargement de la BDD");
    int bit_grid= 0, bit_line1=0 , bit_line2=0;
    bool diff_densite = false;

    if ( file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        QTextStream in( &file ) ;
        QString line = in.readLine() ;
        int nline = 1;

        while ( piece == false  )
        {
            QStringList	parse = line.split(";") ;

            if (( line.isEmpty() )||( line.startsWith("#") ))
            {
                line = in.readLine() ;
                nline++ ;
                continue;
            }

            if ( (int)densite_photo == 0 && (int)line_1+(int)line_2 == 0)
            {
                piece = true;
                nb_piece = 0;
                rotation_piece = 0;
                break;
            }
            if(densite_photo < 2 && densite_photo > 1)
            {
                nb_piece = 5;

                QString grid1,grid2,grid3,grid4;

                grid1 = grid_AS.left(4);
                grid_AS.remove(0,4);
                grid2 = grid_AS.left(4);
                grid_AS.remove(0,4);
                grid3 = grid_AS.left(4);
                grid_AS.remove(0,4);
                grid4 = grid_AS.left(4);
                grid_AS.remove(0,4);

                if ( grid1 == "0100")
                {
                    rotation_piece = 0;
                    piece = true;
                    break;
                }
                else if ( grid2 == "0001")
                {
                    rotation_piece = 3;
                    piece = true;
                    break;
                }
                else if ( grid3 == "1000")
                {
                    rotation_piece = 1;
                    piece = true;
                    break;
                }
                else if ( grid4 == "0010")
                {
                    rotation_piece = 2;
                    piece = true;
                    break;
                }
                else
                {
                    rotation_piece = 0;
                    piece = true;
                    break;

                }

            }
            if (densite_photo > 3 && densite_photo < 4)
            {
                nb_piece = 14;
                bit_grid = comparaison_grid(parse[2],grid_AS);
                bit_line1 = comparaison_line1(parse[3],line_AS1);
                bit_line2 = comparaison_line2(parse[4],line_AS2);

                if (line_2 == 0 && line_1 < 32)
                {
                    rotation_piece = 0;
                    piece = true;
                    break;
                }
                else if (grid > 64 && line_1 == 0 )
                {
                    rotation_piece = 3;
                    piece = true;
                    break;

                }
                else if (line_2 == 0 && line_1 > 64)
                {
                    rotation_piece = 2;
                    piece = true;
                    break;
                }
                else
                {
                    rotation_piece = 1;
                    piece = true;
                    break;

                }
            }

            if(nline >= 31 && nline <= 34 )
            {
                traitement_spe();
                bit_grid = comparaison_grid(parse[2],grid_AS_spe);
                bit_line1 = comparaison_line1(parse[3],line_AS1_spe);
                bit_line2 = comparaison_line2(parse[4],line_AS2_spe);
                diff_densite = comparaison_densite(parse[1].toFloat(),densite_photo);
            }
            else
            {
                densite_photo = tempo_densite;
                bit_grid = comparaison_grid(parse[2],grid_AS);
                bit_line1 = comparaison_line1(parse[3],line_AS1);
                bit_line2 = comparaison_line2(parse[4],line_AS2);
                diff_densite = comparaison_densite(parse[1].toFloat(),densite_photo);
            }
            if( diff_densite == true)
            {
                if (bit_grid < 4 && bit_line1 < 6 && bit_line2 < 6 )
                {
                    nb_piece = parse[0].toInt();
                    rotation_piece = parse[5].toInt();
                    piece = true;
                    break;
                }
            }

            if(in.atEnd() && piece == false)
            {
                envoie_donees();
                return;
            }
            nline++ ;
            line = in.readLine() ;
        }
        file.close();
    }
}
void camera::traitement_spe()
{

    QImage * dest = new QImage(image);
    QImage * dest1 = new QImage (*dest);

    QamImgProcessor *traitement = new QamImgProcessor();

    traitement->setSrcImage(dest);
    traitement->setDstImage(dest1);
    traitement->cut(position_x,position_y,position_w,position_h);// redimmention de l'image en fonction de la cam

    QImage * dest2 = new QImage(*dest1);

    traitement->setSrcImage(dest1);
    traitement->setDstImage(dest2);
    traitement->size(300,300);

    traitement->setSrcImage(dest2);
    traitement->setDstImage(dest1);
    traitement->enhanceWhite(255,15);
    traitement->setSrcImage(dest1);
    traitement->setDstImage(dest2);
    densite_photo = traitement->binarization(145,0);

    grid = traitement->grid(4);
    line_1 = traitement->line(1,1,99,99,50);
    line_2 = traitement->line(99,1,1,99,50);
    line_vert_1 = traitement->line(95,99,95,1,50);
    line_vert_2 = traitement->line(5,1,5,99,50);

    grid_AS_spe = traitement->gridAsString(grid);
    line_AS1_spe = traitement->lineAsString(line_1);
    line_AS2_spe = traitement->lineAsString(line_2);

    delete dest;
    delete dest1;
    delete dest2;
    delete traitement;
}
void camera::nouvelle_tentative()
{
    tempo ++;
    ui->photo->click();
}
void camera::envoie_donees()
{
    if(piece == true)
    {
        attente->set(false);
        ecrir_log("Diagnostic terminé ! ! !");
        ecrir_log_bleu("Piece " + QString::number(nb_piece)+", de rotation : "+QString::number(rotation_piece)+" reconnue en "+QString::number(temps)+" ms");
        m_map->setLocalValue(m_table_holding, "C_Tab_Num", QString::number(nb_piece));
        m_map->setLocalValue(m_table_holding,"C_Tab_Ori", QString::number(rotation_piece));
        m_map->setLocalValue(table,"C_Def","0");
        m_map->setLocalValue(table,"C_Mon","0");


    }
    else if (piece == false)
    {
        attente->set(false);
        if(tempo == 0 || tempo == 1)      ecrir_log_pb("Echec du diagnostic, pièce non trouvée");
        m_map->setLocalValue(table,"C_Def","1");
        m_map->setLocalValue(table,"C_Mon","0");
    }
}

//lancement thread
void camera::communication()
{
    attente->start();
}

// ------------------------------------------------------------------------
// Info découpage
// ------------------------------------------------------------------------
void camera::message_photo()
{
    //QMessageBox::information(this, "Réglage de la photo", "Afin de régler le découpage de la photo utilisater le click gauche pour avoir un réper (vert) pour déterminer le premier poitn de traitement du rectangle. < br />< br /> Puis le client droit au même coordiné afin de tracer un rectangle (rouge) pour obtenir une image parfaite < br/>< br /> Puis cliquer sur Save config");
}

// ------------------------------------------------------------------------
// Remonter d'information
// ------------------------------------------------------------------------
void camera::ecrir_log(QString message)
{
        ui->log->append(message);
}
void camera::ecrir_log_pb(QString message)
{
        ui->log->append("<font color=\"red\">" + message + "<\font>");
}
void camera::ecrir_log_bleu(QString message)
{
        ui->log->append("<font color=\"blue\">" + message + "<\font>");
}


// ------------------------------------------------------------------------
// Déplacement
// ------------------------------------------------------------------------
void camera::mousepoint(int x, int y, int w, int h)
{
    position_x = x;
    position_y = y;
    position_w = w;
    position_h = h;

    //creation_BdD();
}
// ------------------------------------------------------------------------
// Paramétrage
// ------------------------------------------------------------------------
void camera::valeur_bin1(int val)
{
    bin1 = val;
}
void camera::valeur_bin2(int val)
{
    bin2 = val;
}
void camera::valeur_blanc1(int val)
{
    blanc1 = val;
}
void camera::valeur_blanc2(int val)
{
    blanc2 = val;
}
void camera::config()
{
    /*QImage* image_bdd = new QImage();
    image_bdd->load("/home/cellflex-vision/Documents/projet/Base/R2.png");*/
    QGraphicsPixmapItem* conf = new QGraphicsPixmapItem((QPixmap::fromImage(image)));
    //QGraphicsPixmapItem* conf = new QGraphicsPixmapItem((QPixmap::fromImage(*image_bdd)));
    netoyage_bin();
    netoyage_signature();
    scene_config->clear();
    scene_config->addItem(conf);
    ui->fenetre_photo->setScene(scene_config);
    ui->bin1->setReadOnly(false);
    ui->bin2->setReadOnly(false);
    ui->blanc1->setReadOnly(false);
    ui->blanc2->setReadOnly(false);
    ui->save_config->setEnabled(true);

}

void camera::reglage_button()
{
    if(ui->automatique->isChecked())
    {
        ui->photo->setEnabled(false);
    }
    else if(!ui->automatique->isChecked())
    {
        ui->photo->setEnabled(true);
    }
}

void camera::reglage()
{
    error = false;
    piece = false;
    premier_passage = false;
    bin1 = 0;
    bin2 = 190;
    blanc1 = 125;
    blanc2 = 15;
    tempo =0;
    position_x = 161;
    position_y = 70;
    position_w = 319;
    position_h = 324;
    ui->bin1->setReadOnly(true);
    ui->bin2->setReadOnly(true);
    ui->blanc1->setReadOnly(true);
    ui->blanc2->setReadOnly(true);
    ui->photo->setEnabled(false);
    ui->save_config->setEnabled(false);
    ui->exit->setEnabled(false);
    ui->config->setEnabled(false);
    ui->automatique->setChecked(true);
    ui->manuel->setChecked(false);
}
void camera::save_config()
{
    ecrir_log("");
    ecrir_log("position x : " + QString::number(position_x));
    ecrir_log("position y : " + QString::number(position_y));
    ecrir_log("position w : " + QString::number(position_w));
    ecrir_log("position h : " + QString::number(position_h));
    ecrir_log("Configuration sauvegardée !");
    ecrir_log("");
    ui->save_config->setEnabled(false);
}

int camera::comparaison_grid(QString BDD, QString actuel)
{
    int nb_bit = 0;
    unsigned int g = BDD.toUInt(0,2) ^ actuel.toUInt(0,2);
    for(int i = 0; i < 15; i++)
    {
        nb_bit += g & 1; //LSB
        g >>= 1;
    }
    return nb_bit;
}
int camera::comparaison_line1(QString BDD , QString actuel,int min,int max)
{
    int nb_bit = 0;
    unsigned int g = BDD.toUInt(0,2) ^ actuel.toUInt(0,2);

    for(int i = min; i < max; i++)
    {
        nb_bit += g & 1; //LSB
        g >>= 1;
    }
    return nb_bit;
}
int camera::comparaison_line2(QString BDD , QString actuel,int min,int max)
{
    int nb_bit = 0;
    unsigned int g = BDD.toUInt(0,2) ^ actuel.toUInt(0,2);
    for(int i = min; i < max; i++)
    {
        nb_bit += g & 1; //LSB
        g >>= 1;
    }
    return nb_bit;
}
bool camera::comparaison_densite(float BDD, float actuel)
{
    float diff_peuti;
    float diff_grand;
    bool diff = false;

    diff_peuti = BDD * 0.90;
    diff_grand = BDD * 1.20;
    if ((diff_peuti <actuel) && (actuel <  diff_grand))
    {
        diff = true;
    }
    return diff;
}

void camera::creation_BdD()
{
   QDir dir("/home/cellflex-vision/Documents/projet/Base" );
   QStringList filters("*.png");
   dir.setNameFilters(filters);
   QStringList list(dir.entryList());
   QImage * src = new QImage();
   int rotation=0;

   quint32 line2;
   quint32 line1;
   quint64 grid;
   float densite;
   QString ID,gridAString,lineAString1,lineAString2;
   int numPiece;

   QamImgProcessor * traitement = new QamImgProcessor();

   //fichier BdD
   QFile file("/home/cellflex-vision/Documents/projet/config/BDD.csv");
   if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) qDebug() << Qt::endl << "erreure fichier";
   QTextStream flux(&file);
   flux.setEncoding(QStringConverter::Utf8);
   flux << "#piece;" << "densite;" <<"gridASstring;" << "lineASstring;" << "line2ASstring;" << "rotation" << Qt::endl;

   numPiece =0;

   for (int i = 0; i <= 76; i++) //parcour toues les images
   {


       src->load(("/home/cellflex-vision/Documents/projet/Base/"+list.at(i)),"PNG");

       QImage * dest = new QImage(*src);


       traitement->setSrcImage(src);
       traitement->setDstImage(dest);
       //traitement->cut(275,250,320,320);
       traitement->cut(position_x,position_y,position_w,position_h); //redimmentionement de l'image

       QImage * dest1 = new QImage (*dest); //création de l'image avec le redimentionement

       traitement->setSrcImage(dest);
       traitement->setDstImage(dest1);
       traitement->size(300,300);

       if ( i >= 29 && i <= 32)
       {
           traitement->setSrcImage(dest1);
           traitement->setDstImage(dest);
           traitement->enhanceWhite(255,15); // renforcement des blancs

           ecrir_log_pb(list.at(i));

           traitement->setSrcImage(dest);
           traitement->setDstImage(dest1);
           densite = traitement->binarization(145,0);

           grid = traitement->grid(4);
           line1 = traitement->line(1,1,99,99,50);
           line2 = traitement->line(99,1,1,99,50);

           lineAString1 = traitement->lineAsString(line1);
           lineAString2 = traitement->lineAsString(line2);
           gridAString = traitement->gridAsString(grid);

       }
       else
       {
           traitement->setSrcImage(dest1);
           traitement->setDstImage(dest);
           traitement->enhanceWhite(135,10); // renforcement des blancs

           traitement->setSrcImage(dest);
           traitement->setDstImage(dest1);
           densite = traitement->binarization(bin1,bin2); // image en binaire

           grid = traitement->grid(4);
           line1 = traitement->line(1,1,99,99,50);
           line2 = traitement->line(99,1,1,99,50);

           lineAString1 = traitement->lineAsString(line1);
           lineAString2 = traitement->lineAsString(line2);
           gridAString = traitement->gridAsString(grid);

       }
       if(i ==0)
       {
           if( !dest1->save(QString("/home/cellflex-vision/Documents/projet/Base_bin/0"),"PNG"))
           {
               std::cout << "erreur photo !" << std::endl;
           }
       }
       else if( i != 0)
       {
            if( !dest1->save(QString("/home/cellflex-vision/Documents/projet/Base_bin/"+list.at(i)),"PNG"))
            {
                std::cout << "erreur photo !" << std::endl;
            }
        }

       if (rotation == 4 )
       {
           rotation = 0;
       }
       if ( (rotation == 1) && (i == 1))
       {
           rotation = 0;
       }

       list.sort();
       ID = list.at(i);

       if ( i == 0)    numPiece = 0;
       if (i == 1)     numPiece = 1;
       if ( i ==(5+4*(numPiece-1)))    numPiece++;

       flux << numPiece << ";" << densite <<";" << gridAString << ";"<< lineAString1 << ";" << lineAString2 <<";"<< rotation << Qt::endl;

       delete dest;
       delete dest1;
       rotation ++;
   }
   delete src;
   file.close();

   ecrir_log_pb("BDD fini !");

}

