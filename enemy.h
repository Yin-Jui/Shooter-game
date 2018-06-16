#ifndef ENEMY_H

#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class enemy:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
   enemy(QGraphicsItem * parent=0);

signals:
    void collide();

public slots:

   virtual void move();

};

#endif // ENEMY_H
