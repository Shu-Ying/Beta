#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include <QProgressBar>
#include <QMovie>

#include <QTimer>

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

    static int time_pea;

    Player *player;
    Monster *monster;

    QPushButton *btn_attack;
    QPushButton *btn_defence;

    QLabel *lab_Player;
    QLabel *lab_Monster;

    QLabel *lab_Pea;
    QLabel *lab_Round;

    QProgressBar *playerHP;
    QProgressBar *monsterHP;

signals:
    void setPlayerDamage(int num);
    void setMonsterDamage(int num);
};

#endif // WIDGET_H
