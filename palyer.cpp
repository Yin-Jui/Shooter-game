#include"pla


player::player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    int random_number = rand() % 580;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/enemy.png"));

    QTimer * timer1 = new QTimer(this);
    QTimer * timer2 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(attack()));
    timer1->start(50);
    timer2->start(2000);
}
