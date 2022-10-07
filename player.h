#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QThread>

class Player : public QThread
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = 0);

    int getHp();
    int getAttack();
    int getDefence();
signals:
    void setPlayerHp(int num);
public slots:
    void damage(int num);
private:
    int attack; //攻击
    int defence; //防御
    int hpMax;
    int hp;
    int p_damage;
protected:
    void run();
};

#endif // PLAYER_H
