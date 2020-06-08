#ifndef STP_H
#define STP_H

#include <iostream>
#include <qgraphicsview.h>
#include <qtextstream.h>
#include <qprocess.h>

using namespace std;

class STP
{
    private:
        int arr[5][5], arr_work[5][5], arr_zero[5][5];
        int arr_min_x[5], arr_min_y[5], arr_end[6];
        int max_zero_x = 0;
        int max_zero_y = 0;
        int num_road = 0;
        QByteArray _prepareGraph();
        void _graphWalk(QTextStream* stream);
        QGraphicsScene* _scene;
        QGraphicsView* _view;
    public:
        void init(QGraphicsScene* scene, QGraphicsView* view);
        void print();
        void min_x();
        void minus_x();
        void min_y();
        void minus_y();
        int min_x_in_line(int x_line, int x_zero);
        int min_y_in_line(int x_line, int x_zero);
        void make_arr_zero();
        void subtraction_line(int in_x, int in_y);
        void get_max_zero();
        void print_roads();
        int launch_stp();
        void show();

};

#endif // STP_H
