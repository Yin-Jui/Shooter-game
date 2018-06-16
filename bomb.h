#ifndef BOMB_H
#define BOMB_H
#include"weapon.h"
class bomb : public weapon
{
 Q_OBJECT
public:
   bomb();
   virtual ~bomb();

signals:
    void collide2();

public slots:
   virtual void fly();

};
#endif // BOMB_H
