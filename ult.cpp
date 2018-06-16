#include "ult.h"
#include<QList>
#include"enemy.h"
#include"mainwindow.h"
#include"bossr.h"

ult::ult()
{

}
ult::~ult(){}

void ult::fly()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(enemy)){

            emit collide();

            this->scene()->removeItem(colliding_items[i]);

            delete colliding_items[i];
        }
        if (typeid(*(colliding_items[i])) == typeid(bossr)){

            emit collide2();

            this->scene()->removeItem(this);

            delete this;
            return;
        }
    }
    setPos(x(), y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}
