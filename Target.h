#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QObject>

class Target: public QObject, public QGraphicsRectItem {
    //Q_OBJECT
public:
    Target();

public slots:
    void move();
};


#endif // TARGET_H
