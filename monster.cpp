#include "monster.h"
#include <QDebug>

Monster::Monster(QWidget *parent) : QWidget(parent)
{
}
void Monster::monsterMain(QWidget *parent)
{
    hp=100;
    hpMax=100;
    attack=5;
    defence=3;
    m_damage=0;

    mov_Monster = new QMovie(":/images/ConeZombieWalk.gif");
    mov_Monster->start();
    lab_Monster = new QLabel(parent);
    lab_Monster->setGeometry(225,70,165,150);
    lab_Monster->setMovie(mov_Monster);

    pro_Monster = new QProgressBar(parent);
    pro_Monster->setOrientation(Qt::Horizontal);
    pro_Monster->setInvertedAppearance(true);
    pro_Monster->setAlignment(Qt::AlignVCenter);
    pro_Monster->setValue(hp);
    pro_Monster->setGeometry(225,0,175,25);
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
    QTimer *time = new QTimer();
    time->start(35);

    connect(time,&QTimer::timeout,[=]
    {
        static int time_damage=0;
        if(time_damage<num-defence)
        {
            time_damage++;
            pro_Monster->setValue(hp-time_damage);
        } else
        {
            hp-=time_damage;
            time_damage=0;
            time->stop();
        }
    });
}

void Monster::monsterAttack()
{
    QMovie *mov_Attack = new QMovie(":/images/ConeZombieAttack.gif");
    mov_Attack->start();
    lab_Monster->raise();
    lab_Monster->setGeometry(-25,70,165,150);
    lab_Monster->setMovie(mov_Attack);

    QTimer *time = new QTimer();
    time->start(1000);
    connect(time,&QTimer::timeout,[=](){
        time->stop();
        lab_Monster->setGeometry(225,70,165,150);
        lab_Monster->setMovie(mov_Monster);
        emit setPlayerHp(attack);
        emit setPlayerEnabled();
    });
}
