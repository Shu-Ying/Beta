#include "monster.h"

Monster::Monster(QWidget *parent) : QThread(parent)
{
    hp=100;
    hpMax=100;
    attack=5;
    defence=3;
    m_damage=0;
}

int Monster::getHp()
{
    return hp;
}

int Monster::getAttack()
{
    return attack;
}

int Monster::getDefence()
{
    return defence;
}

void Monster::damage(int num)
{
    m_damage=num;
}

void Monster::run()
{
    while(true)
    {
        msleep(25);
        if(m_damage>0&&hp>0)
        {
           emit setMonsterHp(--hp);
           m_damage--;
        }
    }
}

