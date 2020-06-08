#include "stp.h"
#include <iostream>
#include <QApplication>
using namespace std;


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    view.setRenderHints(QPainter::SmoothPixmapTransform);

    STP lab_32;
    lab_32.init(&scene, &view);

    lab_32.print();
    cout << endl;
    lab_32.launch_stp();
    cout << endl;

    lab_32.show();

    return app.exec();
}
