#include "Target.h"

#include <QTimer>
#include <stdlib.h>

Target::Target()
{
    int random_number = rand() % 700;

    // set random position
    setPos(random_number, 0);

    // draw the rect
    setRect(0,0,50,100);

    //connect
    QTimer* timer = new QTimer();


    // old style (compiled, but not work)
    //connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // it works
    connect(timer, &QTimer::timeout, this, &Target::move);

    timer->start(50);
}

void Target::move()
{
    // move down
    setPos(x(), y()+5);

    // delete
    if (pos().x() < 0)
    {
        // what's the different?
        scene()->removeItem(this);
        delete this;
    }
}


