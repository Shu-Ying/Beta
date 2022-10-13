#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QProgressBar>

#include "widget.h"
#include "player.h"

class Monster : public QWidget
{
    Q_OBJECT
public:
    explicit Monster(QWidget *parent = 0);

    int getHp();
    int getAttack();
    int getDefence();

    void monsterMain(QWidget *parent = 0);
signals:
    void setPlayerHp(int num);
    void setPlayerEnabled();
public slots:
    void damage(int num);
    void monsterAttack();
private:
    int hp;
    int hpMax;
    int attack;
    int defence;
    int m_damage;

    QMovie *mov_Monster;
    QLabel *lab_Monster;
    QProgressBar *pro_Monster;
};

#endif // MONSTER_H
