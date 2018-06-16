#ifndef PALYER_H
#define PALYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
   player(QGraphicsItem * parent=0);



};
#endif // PALYER_H
