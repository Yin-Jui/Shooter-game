#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{

public:
    Score(QGraphicsItem * parent=0);

    int getScore();
   int score;
public slots:

    void increase();

private:

};

#endif // SCORE_H
