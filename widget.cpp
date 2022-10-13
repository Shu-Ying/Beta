#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    Monster *monster = new Monster(this);
    monster->monsterMain(this);
    Player *player = new Player(this);
    player->playerMain(this);

    connect(monster,&Monster::setPlayerHp,player,&Player::damage);
    connect(player,&Player::setMonsterHp,monster,&Monster::damage);
    connect(player,&Player::monsterAttack,monster,&Monster::monsterAttack);
    connect(monster,&Monster::setPlayerEnabled,player,&Player::setPlayerEnabled);
}

Widget::~Widget()
{
    delete ui;
}
