#include "bossh.h"
#include <QFont>

bossh::bossh(QGraphicsItem *parent): QGraphicsTextItem(parent){

    bosshealth = 50;


    setPlainText(QString("BOSS: ") + QString::number(bosshealth));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    setPos(500,50);
}

void bossh::decrease(){
    bosshealth--;
    setPlainText(QString("BOSS: ") + QString::number(bosshealth));
}
void bossh::decrease2(){
    bosshealth-=10;
    setPlainText(QString("BOSS: ") + QString::number(bosshealth));
}
int bossh::getbossh(){
    return bosshealth;
}
