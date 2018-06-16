#include"player.h"

player::player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    setPos(300,650);

    setPixmap(QPixmap(":/images/tank.png"));

}
