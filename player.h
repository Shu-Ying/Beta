#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QMovie>
#include <QTimer>

#include "widget.h"
#include "monster.h"

class Player : public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = 0);

    int getHp();
    int getAttack();
    int getDefence();

    int attack;
    int defence;
    int hpMax;
    int hp;
    int p_damage;

    void playerMain(QWidget *parent = 0);
signals:
    void setMonsterHp(int num);
    void monsterAttack();
public slots:
    void damage(int num);
    void setPlayerEnabled();
private:
    QLabel *lab_Player;
    QLabel *lab_Pea;
    QMovie *mov_Player;
    QProgressBar *pro_Player;
    QPushButton *btn_PlayerAttack;
    QPushButton *btn_PlayerDefence;
};



#endif // PLAYER_H
