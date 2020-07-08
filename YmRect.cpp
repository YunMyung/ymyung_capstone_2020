#include "YmRect.h"

#include <QKeyEvent>
#include "Bullet.h"
#include "Target.h"

//#include <QDebug>

void YmRect::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "YmRect knows a key is pushed!!";
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
            setPos(x()-10, y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x() + 100 < 800)
            setPos(x()+10, y());
    }
    else if(event->key() == Qt::Key_Up)
    {
        setPos(x(), y()-10);
    }
    else if(event->key() == Qt::Key_Down)
    {
        setPos(x(), y()+10);
    }
    else if(event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet* bullet = new Bullet();
        bullet->setPos(x(), y()+50);
        scene()->addItem(bullet);
    }
}

void YmRect::spawn()
{
    // create an enemy

    Target* target = new Target();
    scene()->addItem(target);


}
