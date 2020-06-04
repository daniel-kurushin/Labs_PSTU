#include "b_tree.h"
#include <iostream>
#include <QApplication>
using namespace std;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    view.setRenderHints(QPainter::SmoothPixmapTransform);

    B_tree * tree = new B_tree();
    tree->init(&scene, &view);

    tree->insert(7);
    tree->insert(6);
    tree->insert(10);
    tree->insert(1);
    //tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->insert(8);
    tree->insert(12);
    tree->insert(13);
    tree->insert(12);
    tree->show();

    tree->print_max();
    tree->print_min();

    return app.exec();
}
