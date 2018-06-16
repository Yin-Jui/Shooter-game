#ifndef BOSSW_H
#define BOSSW_H
#include"weapon.h"
class boosw : public weapon
{
 Q_OBJECT
public:
   boosw();
   virtual ~boosw();

signals:
    void collide();

public slots:
   virtual void fly();

};

#endif // BOSSW_H
