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
    lab_Monster = new QLabel("123",this);
    lab_Monster->setGeometry(225,70,165,150);
    lab_Monster->setMovie(monster_A);

    playerHP = new QProgressBar(this);
    playerHP->setOrientation(Qt::Horizontal); //设置进度条为水平
    playerHP->setAlignment(Qt::AlignVCenter); //将进度条旁边的字 放到 进度条中
    playerHP->setValue(player->getHp());
    playerHP->setGeometry(0,0,175,25);

    monsterHP = new QProgressBar(this);
    monsterHP->setOrientation(Qt::Horizontal);
    monsterHP->setInvertedAppearance(true);
    monsterHP->setAlignment(Qt::AlignVCenter);
    monsterHP->setValue(monster->getHp());
    monsterHP->setGeometry(225,0,175,25);

    btn_attack = new QPushButton("攻击",this);
    btn_attack->setGeometry(125,250,50,25);


    btn_defence = new QPushButton("格挡",this);
    btn_defence->setGeometry(225,250,50,25);
}

Widget::~Widget()
{
    delete ui;
}
