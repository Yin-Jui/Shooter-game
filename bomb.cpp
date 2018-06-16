#include "bomb.h"
#include<QList>
#include"player.h"
#include"mainwindow.h"
#include<QTimer>

bomb::bomb()
{
  setPixmap(QPixmap(":/images/bomb2.png").scaled(50, 50));
   QTimer *timer = new QTimer;
   timer->start(20);
   connect(timer,SIGNAL(timeout()),this,SLOT(fly()));
}
bomb::~bomb(){}

void bomb::fly()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(player)){
           emit collide2();
            delete this;
            return;
        }
    }
    setPos(x(), y() + 7);
    if(y() > 800) {
        this->scene()->removeItem(this);
        delete this;
    }
}
