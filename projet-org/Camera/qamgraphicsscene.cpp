#include "qamgraphicsscene.h"
#include <QGraphicsView>
#include <QDebug>

#include <iostream>

Qamgraphicsscene::Qamgraphicsscene(QObject* parent, bool withCapture)
  : QGraphicsScene(parent)
  , captureEnabled(withCapture)
  , isCapturing(false)
  , isReticle(false)
{
}

//mise a jour rectangle de capture(carré si Shift)
// et/ou déplacement du réticule

void Qamgraphicsscene::mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    qreal x = mouseEvent->scenePos().x(); //évenement en X de la scene photo
    qreal y = mouseEvent->scenePos().y(); // évenement en Y de la scene photo

    if ((x < 0) || (x > views().at(0)->width() )) return;
    if ((y < 0) || (y > views().at(0)->height() )) return;

    emit mousePosition ( (int)x, (int)y );

    if (isCapturing)
    {
        QRectF rect = rectItem->rect();
        qreal w = x - rect.x();
        qreal h = y - rect.y();
        if(mouseEvent->modifiers() & Qt::ShiftModifier){
            h = w;
        }
        rect.setWidth( w );
        rect.setHeight( h );
        rectItem->setRect (rect);
    }
    if ( isReticle)
    {
        QLineF hLine = QLineF(0, y, views().at(0)->width(), y );
        hLineItem->setLine(hLine);
        QLineF vLine(x,0,x,views().at(0)->height());
        vLineItem->setLine(vLine);
    }
}

void Qamgraphicsscene::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    qreal x = mouseEvent->scenePos().x();
    qreal y = mouseEvent->scenePos().y();

    if(captureEnabled){
        if(mouseEvent->button() == Qt::LeftButton){
            QLineF hLine(0,y, views().at(0)->width(), y);
            hLineItem = this->addLine(hLine, QPen(Qt::darkGreen) );
            QLineF vLine(x,0,x, views().at(0)->height() );
            vLineItem = this->addLine(vLine, QPen(Qt::darkGreen) );
            isReticle = true;
        }
        if (mouseEvent->button() == Qt::RightButton){
            QRectF rect(x,y,0,0);
            rectItem = this->addRect(rect, QPen(Qt::red) );
            isCapturing = true;
        }
    }
}

void Qamgraphicsscene::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
    qreal x = mouseEvent->scenePos().x();
    qreal y = mouseEvent->scenePos().y();
    if(captureEnabled) {
        if(mouseEvent->button() == Qt::LeftButton){
            //this->removeItem(hLineItem);
            //this->removeItem(vLineItem);
            isReticle = false;
            emit mousePoint( (int)x, (int)y );

        }

        if(mouseEvent->button() == Qt::RightButton){
            QRect rect = rectItem->rect().toRect();
            emit mouseRect(rect.x(), rect.y(), rect.width(), rect.height());
            this->removeItem( rectItem);
            isCapturing = false;

        }
    }
}
