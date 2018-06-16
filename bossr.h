#ifndef BOSSR_H
#define BOSSR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include<QTimer>

class bossr:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bossr(QGraphicsItem * parent=0);

    QTimer *timer1;
    QTimer *timer2;

    int hp;
public slots:

    void move();

};



#endif // BOSSR_H
