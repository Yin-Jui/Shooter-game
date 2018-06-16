#ifndef WEAPON_H
#define WEAPON_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class weapon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    weapon(QGraphicsItem * parent=0);

    virtual ~weapon();

    QTimer *timer;

public slots:
    virtual void fly()=0;

};

#endif // WEAPON_H
