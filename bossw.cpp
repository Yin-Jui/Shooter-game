#include "bossw.h"
#include<QList>
#include"player.h"
#include"mainwindow.h"
#include<QTimer>
#include<stdlib.h>

boosw::boosw()
{
  setPixmap(QPixmap(":/images/bossw2.png").scaled(75, 75));
   QTimer *timer = new QTimer;
   timer->start(250);
   connect(timer,SIGNAL(timeout()),this,SLOT(fly()));
}
boosw::~boosw(){}

void boosw::fly()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(player)){
           emit collide();
            delete this;
            return;
        }
    }
    int random_number = rand() % 2;
   if(random_number==0){
    setPos(x()-18, y() + 48);
    if(y() > 800||x()>600) {
        this->scene()->removeItem(this);
        delete this;
    }
   }
   if(random_number==1){
    setPos(x()+18, y() + 48);
    if(y() > 800||x()>600) {
        this->scene()->removeItem(this);
        delete this;
    }
   }
}
