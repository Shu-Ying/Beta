#ifndef MONSTER_H
#define MONSTER_H

#include <QWidget>

class Monster : public QWidget
{
    Q_OBJECT
public:
    explicit Monster(QWidget *parent = 0);
    int getHp();
signals:

public slots:
private:
    int hp;
    int hpMax;
    int attack;
    int defence;
};

#endif // MONSTER_H
