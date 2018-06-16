#ifndef BULLET_H
#define BULLET_H
#include"weapon.h"

class bullet : public weapon
{
 Q_OBJECT
public:
    bullet();

    virtual ~bullet();
signals:
    void collide();
    void collide2();

public slots:
    virtual void fly();

};

#endif // BULLET_H
