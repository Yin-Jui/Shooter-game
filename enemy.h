#ifndef ENEMY_H

#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class enemy:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
   enemy(QGraphicsItem * parent=0);
   QTimer *timer1;

signals:
    void collide();

public slots:

   virtual void move();
    void check();

};

#endif // ENEMY_H
