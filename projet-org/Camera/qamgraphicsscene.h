#ifndef QAMGRAPHICSSCENE_H
#define QAMGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>

class Qamgraphicsscene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Qamgraphicsscene(QObject *parent = 0, bool withCapture = true);

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* mouseEvent);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent);

signals:
    void mousePoint(int x, int y);
    void mousePosition(int x, int y);
    void mouseRect(int x, int y, int w, int h);

public slots:

private :
    bool captureEnabled;
    bool isCapturing;
    bool isReticle;
    QGraphicsRectItem* rectItem;
    QGraphicsLineItem* hLineItem;
    QGraphicsLineItem* vLineItem;
};

#endif // QAMGRAPHICSSCENE_H
