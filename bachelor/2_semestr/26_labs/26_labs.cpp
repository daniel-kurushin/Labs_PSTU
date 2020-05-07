#include <iostream>

using namespace std;

class Error
{
    string str;
    public:
    Error(string s)
    {
        str = s;
    }
    void what()
    {
        cout << str << endl;
    }
};

class List
{
    private:
    int count = 0;
    struct list
    {
        int data;
        struct list * next;
    };
    list * head;
    public:
    List ()
    {
        count = 0;
        head = NULL;
    }
    void add(int in_data)
    {
        count++;
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
    int & operator[](int index)
    {
        if (index >= count) 
            throw Error("over index");
        list * tmp = head;
        for(int counter = 0; counter < index; counter++)
        {
            tmp = tmp -> next;
        }
        return tmp -> data;
    }
    int & operator() ()
    {
        if (count == 0) throw Error("list is empty!");
        return count;
    }
    int& operator*(int num)
    {
        if(num < 0) throw Error("input num");
        list * tmp = head;
        while(tmp != NULL)
        {
            tmp -> data = tmp -> data * num;
            tmp = tmp -> next;
        }
        return tmp -> data;
    }
};

int main(int argc, char* argv[])
{
    List tree;
    try
    {
        for(int i = 0; i < 5; i++)
        {
            tree.add(i);
        }
        tree * 5;
        tree.print();
        cout << tree[7] << endl;
        tree * -1;
        tree.print();
    }
    catch(Error e)
        {
            e.what();
        }
    return 0;
}
