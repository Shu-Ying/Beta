#include "player.h"

Player::Player(QWidget *parent) :QThread(parent)
{
    hp=100;
    hpMax=100;
    attack=10;
    defence=3;
    p_damage=0;
}
int Player::getHp()
{
    return hp;
}

int Player::getAttack()
{
    return attack;
}

int Player::getDefence()
{
    return defence;
}

void Player::damage(int num)
{
    p_damage=num;
}

void Player::run()
{
    while(true)
    {
        msleep(25);
        if(p_damage>0&&hp>0)
        {
            emit setPlayerHp(--hp);
            p_damage--;
        }
    }
}
