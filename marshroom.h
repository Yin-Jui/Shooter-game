#ifndef MARSHROOM_H
#define MARSHROOM_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class marshroom:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
   marshroom(QGraphicsItem * parent=0);
   QTimer *timer1;

signals:
    void collide();

public slots:

   virtual void move();
    

};




#endif // MARSHROOM_H
