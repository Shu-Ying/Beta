#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>

class Player : public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = 0);
    int getHp();


signals:

public slots:

private:
    int attack; //攻击
    int defence; //防御
    int hpMax;
    int hp;
};

#endif // PLAYER_H
