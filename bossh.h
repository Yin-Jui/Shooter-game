#ifndef BOSSH_H
#define BOSSH_H
#include <QGraphicsTextItem>

class bossh: public QGraphicsTextItem{
public:
    bossh(QGraphicsItem * parent=0);
    void decrease();
    void decrease2();
    int getbossh();

    int bosshealth;
};
#endif // BOSSH_H
