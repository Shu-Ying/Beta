#include "player.h"
#include <QDebug>

Player::Player(QWidget *parent) : QWidget(parent)
{
}

void Player::playerMain(QWidget *parent)
{
    hp=100;
    hpMax=100;
    attack=10;
    defence=3;
    p_damage=0;

    mov_Player = new QMovie(":/images/Peashooter.gif");
    mov_Player ->start(); //动图执行
    lab_Player = new QLabel(parent);
    lab_Player->setGeometry(25,145,75,75); //设置 X Y 长 宽
    lab_Player->setMovie(mov_Player); //set动图
    //lab_Player->setVisible(false);

    pro_Player = new QProgressBar(parent);
    pro_Player->setOrientation(Qt::Horizontal); //设置进度条为水平
    pro_Player->setAlignment(Qt::AlignVCenter); //将进度条旁边的字 放到 进度条中
    pro_Player->setValue(hp);
    pro_Player->setGeometry(0,0,175,25);

    btn_PlayerAttack = new QPushButton("攻击",parent);
    btn_PlayerAttack->setGeometry(125,250,50,25);

    QTimer *time = new QTimer(parent);
    QImage *img_pea = new QImage(":/images/Pea.png");
    lab_Pea = new QLabel(parent);
    lab_Pea->setGeometry(75,130,75,75); //设置 X Y 长 宽
    lab_Pea->setPixmap(QPixmap::fromImage(*img_pea));
    lab_Pea->lower(); //置于下层, 以免覆盖其他图片
    lab_Pea->setVisible(false); //隐藏

    btn_PlayerDefence = new QPushButton("格挡",parent);
    btn_PlayerDefence->setGeometry(225,250,50,25);

    connect(btn_PlayerAttack,&QPushButton::clicked,[=]
    {
        btn_PlayerAttack->setEnabled(false);
        btn_PlayerDefence->setEnabled(false);
        time->start(7);
    });

    connect(time,&QTimer::timeout,[=]
    {
        static int time_pea=75;
        if(time_pea>=300)
        {
            lab_Pea->setVisible(false);
            lab_Pea->setGeometry(75,130,75,75);
            time_pea=75;
            emit setMonsterHp(attack);
            emit monsterAttack();
            time->stop();
        } else
        {
            lab_Pea->setVisible(true);
            lab_Pea->setGeometry(time_pea+=3,130,75,75);
        }
    });
}
void Player::damage(int num)
{
    QTimer *time = new QTimer();

    time->start(35);

    connect(time,&QTimer::timeout,[=]
    {
        static int time_damage=0;
        if(time_damage<num-defence)
        {
            time_damage++;
            pro_Player->setValue(hp-time_damage);
        } else
        {
            hp-=time_damage;
            time_damage=0;
            time->stop();
        }
    });
}

void Player::setPlayerEnabled()
{
    btn_PlayerAttack->setEnabled(true);
    btn_PlayerDefence->setEnabled(true);
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
