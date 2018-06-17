#ifndef BOMB_H
#define BOMB_H
#include"weapon.h"
class bomb : public weapon
{
 Q_OBJECT
public:
   bomb();
QTimer *timer;
   virtual ~bomb();

signals:
    void collide2();

public slots:
   virtual void fly();

    void check();
};
#endif // BOMB_H
