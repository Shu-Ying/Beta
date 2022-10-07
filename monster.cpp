#include "monster.h"

Monster::Monster(QWidget *parent) : QWidget(parent)
{
    hp=100;
    hpMax=100;
    attack=5;
    defence=3;
}

int Monster::getHp()
{
    return hp;
}

