#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include <QProgressBar>
#include <QMovie>

#include "player.h"
#include "monster.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    Player *player;
    Monster *monster;

    QPushButton *btn_attack;
    QPushButton *btn_defence;

    QLabel *lab_Player;
    QLabel *lab_Monster;


    QProgressBar *playerHP;
    QProgressBar *monsterHP;
};

#endif // WIDGET_H
