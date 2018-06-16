#ifndef ULT_H
#define ULT_H
#include"weapon.h"
class ult : public weapon
{
 Q_OBJECT
public:
   ult();
   virtual ~ult();

signals:
    void collide();
    void collide2();

public slots:
   virtual void fly();

};
#endif // ULT_H
