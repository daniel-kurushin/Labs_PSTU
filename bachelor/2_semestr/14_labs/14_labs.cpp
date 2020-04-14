//Духанин Алексей, лаб. 14
#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;

typedef struct node 
{
	char value;
    struct node *next;
} node;


void push(node **head, char data) 
{
    node *tmp = (node*) malloc(sizeof(node));
    tmp -> value = data;
    tmp -> next = (*head);
    (*head) = tmp;
}

void make_list(node **head, char *arr, size_t size) 
{
    size_t i = size - 1;
    if (arr == NULL or size == 0) 
    {
        return;
    }
    do 
    {
        push(head, arr[i]);
    } while(i--!=0);
}

void printlist(const node *head) 
{
    while (head) 
    {
        cout << head -> value << '\t';
        head = head->next;
    }
    cout << endl;
}

void tolist(node *head, unsigned n, char val) 
{
    unsigned i = 0;
    node *tmp = NULL;
    while (i < n and head->next) 
    {
        head = head->next;
        i++;
    }
    tmp = (node*) malloc(sizeof(node));
    tmp->value = val;
    if (head->next) 
    {
        tmp->next = head->next;
    }
    else 
    {
        tmp->next = NULL;
    }
    head->next = tmp;
}

typedef struct __node
{
    void * data;
    struct __node *follow;
    struct __node *prev;
}_node;

typedef struct _dls
{
    size_t nums;
    _node *header;
    _node *tail;
}dls;

dls* create_dls()
{
    dls *tmp = (dls*)malloc(sizeof(dls));
    tmp -> nums = 0;
    tmp -> header = tmp -> tail = NULL;
    return tmp;
}

void delete_dls(dls **lst)
{
    _node * tmp = (*lst) -> header;
    _node * next = NULL;
    while(tmp)
    {
        next = tmp -> follow;
        free(tmp);
        tmp = next;
    }
    free(*lst);
    (*lst) = NULL;
}

void infront(dls *lst, void * num)
{
    _node * tmp = (_node*)malloc(sizeof(_node));
    if(tmp == NULL)
    {
        exit(1); 
    }
    tmp -> data = num;
    tmp -> follow = lst -> header;
    tmp -> prev = NULL;
    if (lst -> header)
    {
        lst -> header -> prev = tmp;
    }
    lst -> header = tmp;
    if(lst -> tail == NULL)
    {
        lst -> tail = tmp;
    }
    lst -> nums++;
}
void inback(dls *lst, void * num)
{
    _node * tmp = (_node*)malloc(sizeof(_node));
    if(tmp == NULL)
    {
        exit(1);
    }
    tmp -> data = num;
    tmp -> follow =NULL;
    tmp -> prev = lst -> tail;
    if (lst -> tail)
    {
        lst -> tail -> follow = tmp;
    }
    lst -> tail = tmp;
    if(lst -> header == NULL)
    {
        lst -> header = tmp;
    }
    lst -> header = tmp;
    lst -> nums++;
}

_node* getnn(dls *lst, size_t index)
{
    _node *tmp = lst -> header;
    size_t counter = 0;
    while(tmp and counter < index)
    {
        tmp = tmp -> follow;
        counter++;
    }
    return tmp;
}

void * delete_elem(dls *lst, size_t index)
{
    _node *elem = NULL;
    void * tmp = NULL;
    elem = getnn(lst, index);
    if (elem == NULL)
    {
        exit(1);
    }
    if (elem -> prev)
    {
        elem -> prev -> follow = elem -> follow;
    }
    if (elem -> follow)
    {
        elem -> follow -> prev = elem -> prev;
    }
    tmp = elem -> data;
    if(! elem -> prev)
    {
        lst -> header = elem -> follow;
    }
    if (!elem -> follow)
    {
        lst -> tail = elem -> prev;
    }
    free(elem);
    lst -> nums--;
    return tmp;
}
/*
void print_dls (dls * lst)
{
    _node * tmp = lst -> tail;
    while (tmp)
    {
        cout << tmp -> data << '\t';
        tmp = tmp -> follow;
        cout << 8 << endl;
    }
    cout << endl;
}
*/
void printInt(void *data) {
    printf("%d ", *((int*) data));
}
void printDblLinkedList(dls *lst, void (*fun)(void*)) {
    _node *tmp = lst->header;
    while (tmp) {
        fun(tmp->data);
        tmp = tmp->follow;
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    node* head = NULL;
    string word = argv[1];
    int pos = atoi(argv[2]);
    int leng_word = word.length();
    make_list(&head, argv[1], leng_word);
    printlist(head);
    char *elem = argv[3];
    char data = *elem;
    tolist(head, pos,data);
    printlist(head);
    
    dls *lst = create_dls();
    int arr[10]= {3, 8, 12, 13, 74, 92, 19, 6, 1, 5};
    for(int counter = 0; counter < 10; counter++)
    {
        if(counter < 5)
        {
            infront(lst, &arr[counter]);
        }
        else
        {
            inback(lst, &arr[counter]);
        }
    }
    //inback(lst, 7);
    //print_dls(lst);
    printDblLinkedList(lst, printInt);
    return 0;
}
