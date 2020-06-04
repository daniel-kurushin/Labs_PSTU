#include "b_tree.h"
#include <iostream>
using namespace std;

void B_tree::init(QGraphicsScene* scene, QGraphicsView* view)
{
    this->_root = NULL;
    this->_scene = scene;
    this->_view = view;
}

void B_tree::insert(int a)
{
    Node* tmp = new Node;
    tmp->data = a;
    tmp->left = NULL;
    tmp->right = NULL;

    if(this->_root == NULL)
    {
        tmp->p = NULL;
        this->_root = tmp;
    }
    else
    {
        Node* cElem = this->_root;
        Node* parent = NULL;

        while(cElem != NULL)
        {
            parent = cElem;
            cElem = (a < cElem->data) ? cElem->left : cElem->right;
        }

        tmp->p = parent;
        if(a < parent->data)
        {
            parent->left = tmp;
        }
        else
        {
            parent->right = tmp;
        }
    }
}

Node* B_tree::findElem(int val, Node* p)
{
    if(p != NULL)
    {
        if(val == p->data) return p;

        if(val < p->data)
        {
            return findElem(val, p->left);
        }
        else
        {
            return findElem(val, p->right);
        }
    }
    else
    {
        return NULL;
    }
}

Node* B_tree::findElem(int val)
{
    return this->findElem(val, this->_root);
}

Node* B_tree::findSuccessor(int val)
{
    Node* startNode = this->findElem(val);
    Node* parent = startNode;

    startNode = startNode->right;
    while(startNode != NULL && startNode->left != NULL)
    {
        parent = startNode;
        startNode = startNode->left;
    }
    return startNode;
}

void B_tree::_graphWalk(Node* p, QTextStream *stream)
{
    if (p != NULL)
    {
        *stream << "\t\t" << "n" << p->data << "[label=\"" << p->data <<"\"];" << endl;

        if(p->left != NULL)
        {
            *stream << "\t\tn" << p->data << "--" << "n" << p->left->data << ";" << endl;
            this->_graphWalk(p->left, stream);
        }
        else
        {
            *stream << "\t\t" << "n" << p->data << "leftNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << p->data << "--" << "n" << p->data << "leftNull" << endl;
        }

        if(p->right != NULL)
        {
            *stream << "\t\tn" << p->data << "--" << "n" << p->right->data << ";" << endl;
            this->_graphWalk(p->right, stream);
        }
        else
        {
            *stream << "\t\t" << "n" << p->data << "rightNull" << "[style=\"filled\",label=\"NULL\"];" << endl;
            *stream << "\t\tn" << p->data << "--" << "n" << p->data << "rightNull" << endl;
        }
    }
}

QByteArray B_tree::_prepareGraph()
{
    QByteArray a = QByteArray();

    QTextStream stream(&a, QIODevice::ReadWrite);
    stream << "graph ""{" << endl;
    stream << "\tnode[fontsize=10,margin=0,width=\".4\", height=\".3\"];" << endl;
    stream << "\tsubgraph cluster17{" << endl;

    this->_graphWalk(this->_root, &stream);
    stream << "\t}\n" << "}" << endl;
    stream.flush();

    return a;
}

void B_tree::show()
{
    QProcess* p = new QProcess();
    QByteArray a = this->_prepareGraph();

    p->setProcessChannelMode(QProcess::MergedChannels);
    p->start("dot", QStringList() << "-Tpng");
    p->write(a);

    QByteArray data;
    QPixmap pixmap = QPixmap();

    while(p->waitForReadyRead(100))
    {
        data.append(p->readAll());
    }

    pixmap.loadFromData(data);

    this->_scene->addPixmap(pixmap);
    this->_view->show();
}
