#include "Bullet.h"
#include "Target.h"

#include <QTimer>
#include <QList>

Bullet::Bullet()
{
    // draw the rect
    setRect(0,0,50,10);

    //connect
    QTimer* timer = new QTimer();


    // old style (compiled, but not work)
    //connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // it works
    connect(timer, &QTimer::timeout, this, &Bullet::move);

    timer->start(50);
}

void Bullet::move()
{
    // if bullet collides with enemy, destory both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Target))
        {
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x()-10, y()-5);

    // delete
    if (pos().x() < 0)
    {
        // what's the different?
        scene()->removeItem(this);
        delete this;
    }
}


