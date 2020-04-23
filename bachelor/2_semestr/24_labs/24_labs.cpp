#include <iostream>

using namespace std;

class Pair
{
    private:
    int first;
    double second;
    public:
    Pair()
    {
        first = 4;
        second = 5.56;
    }
    void print()
    {
        cout << first << ":" << second << endl;
    }
};

template <typename T>
class List
{
    private:
    struct list
    {
        T data;
        struct list *next;
    };
    list *head;
    public:
    List()
    {
        head = NULL;
    }
    void add(T in_data)
    {
        list * tmp = new list;
        tmp -> data = in_data;
        tmp -> next = head;
        head = tmp;
    }
    void print()
    {
        list * tmp = head;
        while(tmp != NULL)
        {
            cout << tmp -> data << '\t';
            tmp = tmp -> next;
        }
        cout << endl;
    }
    T& operator [](int index)
    {
        list * tmp = head;
        for(int counter = 0; counter < index; counter++)
        {
            tmp = tmp -> next;
        }
        return tmp -> data;
    }
    T& operator *(int num)
    {
        list * tmp = head;
        while(tmp != NULL)
        {
            tmp -> data = tmp -> data * num;
            tmp = tmp -> next;
        }
        return tmp -> data; 
    }
};

int main(int argc, char * argv[])
{
    Pair laba;
    laba.print();
    
    List <int> new_list;
    for(int counter = 0; counter < 5; counter++)
    {
        new_list.add(counter);
    }
    new_list.print();
    cout << new_list[4] << endl;
    new_list * 5;
    new_list.print();
    
    return 0;
}
