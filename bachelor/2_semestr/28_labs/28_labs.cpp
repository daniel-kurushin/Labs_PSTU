#include <iostream>
#include <deque>
#include <vector>

using namespace std;

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
    friend ostream& operator << <> (ostream& out, const List <T> a);
    friend istream& operator >> <> (istream& in, const List <T> a);
};

template <class T>
ostream& operator << (ostream & out, const List <T> &a)
{
    //list *tmp = head;
    while(tmp != NULL)
    {
        out << a -> data << " ";
        a = a -> next;
    }
    return out;
}

template <class T> 
istream& operator >> (istream & in, List <T> & a)
{
    while(tmp != NULL)
    {
        in >> a -> data;
        a = a -> next;
    }
    return in;
}

deque <int> deq_1

void init_deq1()
{
    cout << "my deque - " ;
    for(int i = 0; i < 5; i++)
    {
        deq_1.pop_front(i);
        cout <<  i << '\t';
    }
    cout << endl;
}

int min_deq1()
{
    int min = deq_1[0];
    for(int i = 1; i < 5; i++)
    {
        if(deq_1[i] < min)
        {
            min = deq_1;
        }
    }
    deq_1.pop_front(min);
    return min;
}

int del_deq1()
{
    int sr = (1 + 2 + 3 + 4) / 5;
    for(int i = 0; i < 5; i++)
    {
        if(deq_1[i] < sr)
        {
            for(int j = i + 1; j < 5; j++)
            {
                deq_1[j] = deq_1[j + 1];
                deq_1.front();
            }
        }
    }
    return sr;
}

int diff_deq1()
{
    int diff = 4 - 2;
    cout << "end my deq - ";
    for(int i = 0; i < 3; i++)
    {
        deq_1[i] -= diff;
        cout << deq_1[i] << '\t';
    }
    cout << endl;
}

template <class T>
class Vector
{
    private:
    vector <T> v;
    int len;
    public:
    Vector()
    {
        len = 0;
    }
    Vector(int n)
    {
        T a;
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);
        }
        len = v.size();
    }
    void print()
    {
        for(int i = 0; i < len; i++)
        {
            cout << v[i] << '\t';
        }
        cout << endl;
    }
    void min_chek()
    {
        for(int i = 0; i < len; i++)
        {
            
        }
    }
};

int main (int argc, char* argv[])
{
    init_deq1();
    min_deq1();
    del_deq1();
    diff_deq1();
    
    
    return 0;
}
