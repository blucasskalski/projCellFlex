#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <QObject>
#include <QImage>
#include <QColor>


class Traitement : public QObject
{
    Q_OBJECT
public:
    explicit Traitement(QObject *parent = 0);

    void setSrcImage(QImage* img ) ; //image source
    void setDstImage(QImage* img ) ; //image destination

    inline QString lastAction() const { return m_lastCall ; }//récupère sous forme de texte la dernière opération effectuée


    typedef enum { Rgb, Red, Green, Blue } PrimaryColor ; //couleur RVB
    typedef enum { Blur, Embossing, HighPass, SobelH, SobelV, Laplace } Filter ;
    typedef enum { Horizontal, Vertical } Axis ;
    typedef enum { Left, Right, Top, Bottom } Direction ;
    typedef enum { Or, And, Xor, Add, Sub } Operator ;
    typedef enum { Nearest, Bilinear, MitchellNetravali, CatmullRom, BSpline, Hermite, Lanczos } Interpolation ;

    // opérations de base
    void mask(QImage maskImg, Operator op = Or ) ;

    // filtrage spectral
    void negative(PrimaryColor color = Rgb ) ;
    double binarization(int low = 0, int high = 127 ) ;
    void equalization(PrimaryColor color = Rgb ) ;
    void brightness(int val = 10, PrimaryColor color = Rgb  ) ;
    void contrast(int val = 10, PrimaryColor color = Rgb ) ;
    void gamma(int val = 22, PrimaryColor color = Rgb ) ;
    void inversion(int threshold = 127, PrimaryColor color = Rgb ) ;
    void expansion(int val = 1, PrimaryColor color = Rgb ) ;
    void enhanceWhite(int threshold = 240, int gap = 10 ) ;

    // filtrage spatial
    void matrix(Filter filter = HighPass) ;
    void area(int size = 3, PrimaryColor color = Rgb ) ;
    void dilatation(int size = 3, PrimaryColor color = Rgb ) ;
    void erosion(int size = 3, PrimaryColor color = Rgb ) ;

    // traitements chromatiques
    void grayScale(int method = 0 ) ;
    void solarization(int low = 0, int high = 127, PrimaryColor color = Rgb ) ;
    void sepia() ;
    void balance(int dr, int dg, int db ) ;
    void posterization(int depth = 4, PrimaryColor color = Rgb ) ;
    void falseColor(int paletteSize = 16 ) ;

    // transformations géométriques
    void reflection(Axis axis = Horizontal ) ;
    void tilt(Direction direction = Left ) ;
    void cut(int x = 0, int y = 0, int w = 100, int h = 100 ) ;
    void size(int w, int h ) ;
    void scale(double xs, double ys, Interpolation interpolation = Bilinear ) ;
    void rotate(double angle, Interpolation interpolation = Bilinear ) ;
    void trapezium(Direction side, int size, int offset = 0 ) ;

    // signatures
    double density( QColor color = Qt::black ) ;
    quint64 grid(int ppline = 4, int margin = 1 ) ;
    void marker(QImage* img, int x, int y, int r = 0, int g = 0, int b = 0 ) ;
    quint32 line(int w1 = 1, int h1 = 1, int w2 = 99, int h2 = 99, int percent = 50 ) ;
    int compareGrid(quint64 grid1, quint64 grid2 , int ppline = 4 ) ;
    quint64 rotateGrid(quint64 grid, int ppline = 4, int angle = 1 ) ;
    QString lineAsString(quint32 line, bool withSeparator = false ) ;
    QString gridAsString(quint64 grid, int ppline = 4, bool withSeparator = false ) ;


protected:
    void normalize(int& value ) ;
    inline QImage* srcImg() { return m_srcImg ; }
    inline QImage* dstImg() { return m_dstImg ; }
    inline void setLastAction(const QString& s ) { m_lastCall = s ; }

signals:

public slots:

private :

    QString filterAsString(Filter filter ) ;
    QString primaryColorAsString(PrimaryColor color ) ;
    QString axisAsString(Axis axis ) ;
    QString directionAsString(Direction direction ) ;
    QString operatorAsString(Operator op ) ;
    QString interpolationAsString(Interpolation interpolation ) ;

    void resetSpectrum() ;
    void initSpectrum(QImage* img ) ;
    int lowSpectrumThreshold(QImage* img, int percent, PrimaryColor color ) ;
    int highSpectrumThreshold(QImage* img, int percent, PrimaryColor color ) ;


    QRgb nearest(double dx, double dy, int xi, int yi ) ;
    QRgb bilinear(double dx, double dy, int xi, int yi ) ;
    QRgb bicubic(double dx, double dy, int xi, int yi, Interpolation interpolation ) ;
    double cubic(double delta, double v0, double v1, double v2, double v3, Interpolation interpolation ) ;
    double sinc(double x ) ;

    QSize containerRect(QSize size, double angle ) ;

    void horizontalTrapezium(Direction side, int size, int offset ) ;
    void verticalTrapezium(Direction side, int size, int offset ) ;



private:
    QImage*	m_srcImg ;
    QImage*	m_dstImg ;

    QString	m_lastCall ;

    uint	m_spectr[256][3] ;

};

#endif // TRAITEMENT_H
