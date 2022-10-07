#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    player = new Player(this);
    monster = new Monster(this);

    QMovie *player_A = new QMovie(":/images/Peashooter.gif");
    player_A->start(); //动图执行
    lab_Player = new QLabel(this);
    lab_Player->setGeometry(25,145,75,75); //设置 X Y 长 宽
    lab_Player->setMovie(player_A); //set动图

    QMovie *monster_A = new QMovie(":/images/ConeZombieWalk.gif");
    monster_A->start();
    lab_Monster = new QLabel(this);
    lab_Monster->setGeometry(225,70,165,150);
    lab_Monster->setMovie(monster_A);

    playerHP = new QProgressBar(this);
    playerHP->setOrientation(Qt::Horizontal); //设置进度条为水平
    playerHP->setAlignment(Qt::AlignVCenter); //将进度条旁边的字 放到 进度条中
    playerHP->setValue(player->getHp());
    playerHP->setGeometry(0,0,175,25);

    connect(player,&Player::setPlayerHp,playerHP,&QProgressBar::setValue);
    connect(this,&Widget::setPlayerDamage,player,&Player::damage);

    monsterHP = new QProgressBar(this);
    monsterHP->setOrientation(Qt::Horizontal);
    monsterHP->setInvertedAppearance(true);
    monsterHP->setAlignment(Qt::AlignVCenter);
    monsterHP->setValue(monster->getHp());
    monsterHP->setGeometry(225,0,175,25);

    connect(monster,&Monster::setMonsterHp,monsterHP,&QProgressBar::setValue);
    connect(this,&Widget::setMonsterDamage,monster,&Monster::damage);

    btn_attack = new QPushButton("攻击",this);
    btn_attack->setGeometry(125,250,50,25);

    QTimer *time = new QTimer(this);

    QImage *img_pea = new QImage(":/images/Pea.png");
    lab_Pea = new QLabel(this);
    lab_Pea->setGeometry(75,130,75,75); //设置 X Y 长 宽
    lab_Pea->setPixmap(QPixmap::fromImage(*img_pea));
    lab_Pea->lower(); //置于下层, 以免覆盖其他图片
    lab_Pea->setVisible(false); //隐藏

    connect(btn_attack,&QPushButton::clicked,[=]
    {
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
            emit setMonsterDamage(player->getAttack()-monster->getDefence());
            time->stop();
        } else
        {
            lab_Pea->setVisible(true);
            lab_Pea->setGeometry(time_pea+=3,130,75,75);
        }
    });


    btn_defence = new QPushButton("格挡",this);
    btn_defence->setGeometry(225,250,50,25);

    connect(btn_defence,&QPushButton::clicked,[=]
    {
        emit setPlayerDamage(monster->getAttack()-player->getDefence());
    });

    player->start();
    monster->start();
}

Widget::~Widget()
{
    delete ui;
}
