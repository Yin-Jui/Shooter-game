#include"marshroom.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include"mainwindow.h"
#include"bullet.h"
#include"bomb.h"
#include"player.h"
marshroom::marshroom(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    int random_number = rand() % 550;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/Mushroom.png").scaled(50, 50));

    timer1 = new QTimer(this);
    timer1->start(50);
    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
}
void marshroom::move(){


    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(player)){

            emit collide();
            this->scene()->removeItem(this);
            delete this;

            return;
        }
    }
    setPos(x(),y()+5);

    if (pos().y() > 800){

       this->scene()->removeItem(this);

       delete this;
    }
}
