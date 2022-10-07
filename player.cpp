#include "player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
    hp=100;
    hpMax=100;
    attack=10;
    defence=10;
}

int Player::getHp()
{
    return hp;
}

