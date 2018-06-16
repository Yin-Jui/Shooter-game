#include "ultlimit.h"
#include <QFont>

ultlimit::ultlimit(QGraphicsItem *parent): QGraphicsTextItem(parent){

    limit =3;
    setPlainText(QString("ULT: ") + QString::number(limit));
      setDefaultTextColor(Qt::black);
     setFont(QFont("times",16));
     setPos(30,70);
}
void ultlimit::decrease(){
    limit--;
    setPlainText(QString("ULT: ") + QString::number(limit));
}
int ultlimit::getlimit(){

    return limit;
}
