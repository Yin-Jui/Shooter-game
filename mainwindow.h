#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "bullet.h"
#include"enemy.h"
#include "score.h"
#include <QKeyEvent>
#include"generatew.h"
#include"player.h"
#include"health.h"
#include <ultlimit.h>
#include"bossr.h"
#include"bossh.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene *scene;
    Score * sc;
    Health *health;
    bossh *bosshealth;
    ultlimit *ultlim;
    static bool slow;
    void mainmenu();
    void gameover();
    void gameover2();
    void drawpanel();
    int second;
    bool upgrade;
    QGraphicsTextItem *tim;


public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    void scoreincrease();
    void spawn();
    void healthdecrease();
    void ultdecrease();
    void increasetime();
    void bossmanage();
    void bossdecrease();
    void bossdecrease2();
    void spawn2();
    void upg();
private:
    Ui::MainWindow *ui;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *gametime;
    weapon *w;
    player *p;
    bossr *boss;

    int gamingtime;
    bool bossexist;
    bool game;


    void drawpanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawGUI();

};

#endif // MAINWINDOW_H
