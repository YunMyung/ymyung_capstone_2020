#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
#include "YmRect.h"
#include <QGraphicsView>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    // Create an item to put into the scene
    YmRect* player = new YmRect();
    player->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add a view
    QGraphicsView* view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    // change default size of the window
    view->setFixedSize(800,600);

    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()*0.8, view->height() - (player->rect().height() * 1.5));

    //to show enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, player, &YmRect::spawn);
    timer->start(2000);

    //MainWindow w;
    //w.show();
    return a.exec();
}
