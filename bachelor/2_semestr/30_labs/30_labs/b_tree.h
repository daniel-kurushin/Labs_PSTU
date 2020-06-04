#ifndef BST_H
#define BST_H
#include <iostream>
#include <qgraphicsview.h>
#include <qtextstream.h>
#include <qprocess.h>

using namespace std;

struct Node
{
    Node *p;
    int data;
    Node *left;
    Node *right;
};

class B_tree
{
    public:
        void init(QGraphicsScene* scene, QGraphicsView* view);
        void insert(int a);

        void show();

        Node* findElem(int val);
    protected:
    private:
        Node* findSuccessor(int val);

        QByteArray _prepareGraph();
        void _graphWalk(Node* p,  QTextStream* stream);
        Node* findElem(int val, Node* p);

        Node* _root;
        QGraphicsScene* _scene;
        QGraphicsView* _view;
};

#endif // b_tree
