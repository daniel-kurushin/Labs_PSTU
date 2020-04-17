#include <iostream>
#include <string.h>
	
using namespace std;

struct list
{
    char data;
    struct list *left;
    struct list *right;
};

void print_tree(struct list *p)
{
    if(p != NULL)
    {
        cout << p -> data << endl;
        print_tree(p -> left);
        print_tree(p -> right);
    }
}
int k = 0;
struct list *addlist(struct list * p, char w)
{
    if(p == NULL)
    {
        p = (struct list*)malloc(sizeof(struct list));
        p -> data = w;
        p -> left = p -> right = NULL;
    }
    else if(p -> data > w)
    {
        p -> left = addlist(p -> left, w);
    }
    else
    {
        p -> right = addlist(p -> right, w);
    }
    return p; 
}
int num = 0;
int search(struct list * p, char w)
{
    if(p != NULL)
    {
        if(p -> data == w)
        {
            num++;
            search(p -> left, w);
            search(p -> right, w);
        }
        else
        {
            search(p -> left, w);
            search(p -> right, w);
        }
    }
    
    return num;
}

int main(int argc, char * argv[])
{
    struct list *tree;
    tree = NULL;
    char w;
    cout << "Введите ваши буквы:" << endl;
    while(1)
    {
        cin >> w;
        if(w != '1')
        {
            tree = addlist(tree, w);
        }
        else
        {
            break;
        }
    }
    cout << "_______________" << endl;
    print_tree(tree);
    cout << "Какую букву искать?"  << endl;
    cin >> w;
    search(tree, w);
    cout << num << endl;
    return 0;
}
