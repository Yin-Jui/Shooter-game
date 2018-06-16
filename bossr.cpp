#include"bossr.h"
#include<ctime>
#include<stdlib.h>
#include"weapon.h"
#include"generatew.h"

bossr::bossr(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPos(180,25);

    setPixmap(QPixmap(":/images/redskull3.png"));
    hp=100;
    timer1 = new QTimer();
    timer2 = new QTimer();
    timer1->start(200);
    timer2->start(5000);
    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));

}

void bossr::move(){

    int random_number = rand() % 2;
if(random_number==1){
    if(this->x()>0){
    setPos(this->x()-15,this->y());
    }
}
if(random_number==0){
    if(this->x()<250){
    setPos(this->x()+15,this->y());
}
}
}

