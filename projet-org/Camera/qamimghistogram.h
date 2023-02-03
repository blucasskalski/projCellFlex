#ifndef QAMIMGHISTOGRAM_H
#define QAMIMGHISTOGRAM_H

#include <QWidget>
#include <QPaintEvent>

class QamImgHistogram : public QWidget
{
	Q_OBJECT
  public:
	explicit QamImgHistogram(QWidget *parent = 0 ) ;

	void setImage(QImage& img ) ;

  protected:
	void paintEvent(QPaintEvent* ) ;
	void enterEvent(QEvent* event ) ;
	void leaveEvent(QEvent* event ) ;
	void mouseMoveEvent(QMouseEvent* event ) ;
	void mousePressEvent(QMouseEvent* event ) ;

  private:
	void	clear() ;
	int		xMouse(QMouseEvent* event ) ;

  signals:
	void xTracking(int) ;
	void xClic(int) ;

  public slots:

  private:
	bool	isInit ;
	int		margin ;
	uint	spectr[256][3] ;
} ;

#endif // QAMIMGHISTOGRAM_H
