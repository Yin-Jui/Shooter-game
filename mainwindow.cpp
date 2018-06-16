#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"enemy.h"
#include"player.h"
#include"bossr.h"

#include <QDebug>
#include<QDateTime>
#include"button.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 600, 805)),
    timer1(new QTimer),
    timer2(new QTimer),
    gametime(new QTimer),
    p(new player)

{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/desert2.jpg")));
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   bossexist=false;

    ultlim= new ultlimit();
    scene->addItem(ultlim);

    health = new Health();

    scene->addItem(health);

    sc = new Score();
    scene->addItem(sc);
    scene->addItem(p);

    timer1->start(10);
    timer2->start(2000);
    gametime->start(1000);
    gamingtime = 0;
    connect(gametime,SIGNAL(timeout()),this,SLOT(increasetime()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(spawn()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(bossmanage()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gameover()

{
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
            scene->items()[i]->setEnabled(false);
        }


        drawpanel(0,0,600,800,Qt::black,0.65);


        drawpanel(175,154,270,100,Qt::lightGray,0.75);

        QGraphicsTextItem* Text = new QGraphicsTextItem();
        Text->setPlainText(QString("SCORE: ") + QString::number(sc->score));
        Text->setPos(206,170);
        Text->setDefaultTextColor(Qt::red);
        Text->setFont(QFont("times",36));
        scene->addItem(Text);

}

void MainWindow::gameover2()
{
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
            scene->items()[i]->setEnabled(false);
        }


        drawpanel(0,0,600,800,Qt::black,0.65);


        drawpanel(175,154,270,150,Qt::lightGray,0.75);

        QGraphicsTextItem* Text = new QGraphicsTextItem();
        Text->setPlainText(QString("YOU WIN! ")+"\n"+QString("SCORE: ") + QString::number(sc->score));
        Text->setPos(206,170);
        Text->setDefaultTextColor(Qt::red);
        Text->setFont(QFont("times",36));
        scene->addItem(Text);
}

void MainWindow::drawpanel(int x, int y, int width, int height, QColor color, double opacity)
{
        QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(color);
        panel->setBrush(brush);
        panel->setOpacity(opacity);
        scene->addItem(panel);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        if(p->y()>0){
        p->setPos(p->x(), p->y() - 13);}
    break;
    case Qt::Key_Down:
    case Qt::Key_S:
        if(p->y()+150<800){
            p->setPos(p->x(), p->y() + 13);}
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        if(p->x()>0){
            p->setPos(p->x() - 13, p->y());}
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if(p->x()+50<600){
            p->setPos(p->x() + 13, p->y());}
        break;
    case Qt::Key_Space:
        if((ultlim->getlimit())>0){
            weapon *w;
            w=genw(2);
            w->setPixmap(QPixmap(":/images/nuclear-bomb.png").scaled(150, 150));
            w->setPos(p->x() + p->pixmap().width() / 2 - w->pixmap().width() / 2, p->y() - w->pixmap().height());
            w->connect(timer1, SIGNAL(timeout()), w, SLOT(fly()));
            scene->addItem(static_cast<QGraphicsPixmapItem*>(w));

            w->connect(w,SIGNAL(collide()),this,SLOT(scoreincrease()));
            w->connect(w,SIGNAL(collide2()),this,SLOT(bossdecrease2()));
            w->connect(w,SIGNAL(collide2()),this,SLOT(scoreincrease()));

            ultdecrease();
        }
        break;
    }

}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    weapon *b;
    b=genw(0);//create bullet
    b->setPixmap(QPixmap(":/images/Missile.png").scaled(50, 50));
    b->setPos(p->x() + p->pixmap().width() / 2 - b->pixmap().width() / 2, p->y() - b->pixmap().height());
    b->connect(timer1, SIGNAL(timeout()), b, SLOT(fly()));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));

    b->connect(b,SIGNAL(collide()),this,SLOT(scoreincrease()));
    b->connect(b,SIGNAL(collide2()),this,SLOT(scoreincrease()));
    b->connect(b,SIGNAL(collide2()),this,SLOT(bossdecrease()));
}

void MainWindow::spawn(){

    enemy *e = new enemy();
     e->connect(e,SIGNAL(collide()),this,SLOT(healthdecrease()));
    scene->addItem(e);


    weapon *b;
    b=genw(1);//create bomb
    b->setPos(e->x()+25,e->y()+25);
    scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
    b->connect(b,SIGNAL(collide2()),this,SLOT(healthdecrease()));


}
void MainWindow::scoreincrease(){

    sc->increase();


}
void MainWindow::healthdecrease(){

    health->decrease();

}
void MainWindow::ultdecrease(){

    ultlim->decrease();

}
void MainWindow::increasetime(){
    gamingtime++;
    if(health->health<=0){
        gameover();
    }

}

void MainWindow::bossmanage(){

 if(gamingtime>20&&bossexist!=true){

   boss=new bossr();
   scene->addItem((boss));
   bossexist=true;
   bosshealth = new bossh();
   scene ->addItem(bosshealth);
}


 if(bossexist==true){

     weapon *b;
     b=genw(3);
     b->setPos(boss->x()+20,boss->y()+250);
     scene->addItem(static_cast<QGraphicsPixmapItem*>(b));
     b->connect(b,SIGNAL(collide()),this,SLOT(healthdecrease()));
     weapon *b2;
     b2 = genw(3);
     b2 ->setPos(boss->x()+220,boss->y()+250);
     scene->addItem(static_cast<QGraphicsPixmapItem*>(b2));
     b2->connect(b2,SIGNAL(collide()),this,SLOT(healthdecrease()));

     if(bosshealth->bosshealth<=0){
         gameover2();
     }
 }

}

void MainWindow::bossdecrease()
{
    bosshealth->decrease();
}

void MainWindow::bossdecrease2()
{
    bosshealth->decrease2();
}

