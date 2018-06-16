#ifndef ULTLIMIT_H
#define ULTLIMIT_H
#include <QGraphicsTextItem>

class ultlimit: public QGraphicsTextItem{
public:
   ultlimit(QGraphicsItem * parent=0);
   void decrease();
   int getlimit();

private:
   int limit;
};


#endif // ULTLIMIT_H
