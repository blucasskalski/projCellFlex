#include "config.h"
#include "camera.h"
#include "traitement.h"
#include "QDebug"


config::config()
{
}

// ---------------------------------------------------------------------------
// création de la cartographie locale (remplissage de la 'modbus map')
// ---------------------------------------------------------------------------

/*!
 * Chargement d'une configuration par fichier CSV. Les lignes du fichier
 * liées aux entrées de table sont analysées par la méthode addData().
 * \param filename : chemin d'accès au fichier.
 * \return false si le fichier ne peut être ouvert, true sinon.
 */

bool config::loadMap(const QString& filename )
{
    QFile	file( filename ) ;
    if ( file.open( QIODevice::ReadOnly | QIODevice::Text ) ) {
        QTextStream in( &file ) ;
        QString line = in.readLine() ;
        int nline = 1 ;

        addDataInfo("loading " + filename + "..." ) ;

        while ( !line.isNull() ) {

            if (( line.isEmpty() )||( line.startsWith("#") )) {
                line = in.readLine() ;
                nline++ ;
                continue;
            }

            QStringList	parse = line.split(";") ;

            if ( parse.size() == 2 ) {
                if ( parse[0] == "HOST" ) {
                    if ( m_mode == ClientMode )	m_host = parse[1].trimmed() ;
                }
                else if ( parse[0] == "PORT" ) {
                    m_port = parse[1].trimmed().toUShort() ;
                }
                else if ( parse[0] == "INFO" ) {
                    m_desc = parse[1].trimmed() ;
                }
                else {
                    addDataInfo("unrecognized line", nline ) ;
                }
            }
            else if ( parse.size() == MODBUSMAP_ENTRY_SIZE ) {
                for ( int i = 0 ; i < MODBUSMAP_ENTRY_SIZE ; ++i ) {
                    parse[i] = parse[i].trimmed() ;
                }
                addData( parse, nline ) ;
            }
            else {
                addDataInfo("invalid number of fields", nline ) ;
            }

            line = in.readLine() ;
            nline++ ;
        }
        file.close() ;
        return true ;
    }
    addDataInfo(filename + " not found!") ;
    return false ;
}
