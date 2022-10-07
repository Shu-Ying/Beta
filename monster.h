#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>
#include <QThread>

class Monster : public QThread
{
    Q_OBJECT
public:
    explicit Monster(QWidget *parent = 0);

    int getHp();
    int getAttack();
    int getDefence();
signals:
    void setMonsterHp(int num);
public slots:
    void damage(int num);
private:
    int hp;
    int hpMax;
    int attack;
    int defence;
    int m_damage;
protected:
    void run();
};

#endif // MONSTER_H
