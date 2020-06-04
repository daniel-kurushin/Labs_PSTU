#include "b_tree.h"
#include <iostream>
using namespace std;
int arr_nums[100];


void B_tree::init(QGraphicsScene* scene, QGraphicsView* view)
{
    this->_root = NULL;
    this->_scene = scene;
    this->_view = view;
}
struct Node * in_tree(struct Node * tree, int a)
{
    if(tree == NULL)
    {
        tree = (struct Node*)malloc(sizeof(struct Node));
        tree -> data = a;
        tree -> left = tree -> right = NULL;
    }
    else if (tree -> data >= a)
    {
        tree -> right = in_tree(tree -> right, a);
    }
    else
    {
        tree -> left = in_tree(tree -> left, a);
    }
    return tree;
}

void B_tree::walk(Node *p)
{
    if (p != NULL)
    {
       arr_nums[p -> data] += 1;
       this -> walk(p->left);
       this -> walk(p->right);
    }
}

void B_tree::chek_nums()
{
    for(int i = 0; i < 100; i++)
    {
        arr_nums[i] = 0;
    }
    this -> walk(this -> _root);
}

void B_tree::print_max()
{
    int max, counter;
    max = counter = 0;
    chek_nums();
    counter = arr_nums[0];
    for(int i = 1; i < 100; i++)
    {
        if(counter < arr_nums[i])
        {
            counter = arr_nums[i];
            max = i;
        }
    }

    cout << "Максимальный элемент - " << max << "Количество повторений" << counter << endl;
}

void B_tree::print_min()
{
    int min = 0;
    chek_nums();
    for(int i = 1; i < 100; i++)
    {
        if(arr_nums[i] == 1)
        {
            min = i;
        }
    }

    cout << "Единственный элемент - " << min << endl;
}

void B_tree::insert(int a)
{
    this -> _root = in_tree(this -> _root, a);
}

Node* B_tree::findElem(int val, Node* p)
{
    if(p != NULL)
    {
        if(val == p->data) return p;

        if(val <= p->data)
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
