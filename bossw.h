#ifndef BOSSW_H
#define BOSSW_H
#include"weapon.h"
class boosw : public weapon
{
 Q_OBJECT
public:
   boosw();
   QTimer *timer;
   virtual ~boosw();

signals:
    void collide();

public slots:
   virtual void fly();
    void check();

};

#endif // BOSSW_H
