#ifndef YMRECT_H
#define YMRECT_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>

class YmRect: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();
};

#endif // YMRECT_H
