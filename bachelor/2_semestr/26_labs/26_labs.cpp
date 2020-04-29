#include <iostream>
#include <error.h>
#include <List.h>

using namespace std;

class Error
{
    
};

class List
{
    private:
    struct list
    {
        int data;
        int count = 0;
        struct list * head;
    }
    list * head;
    public:
    List ()
    {
        head = NULL;
    }
    void add(int in_data)
    {
        
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
        
    }
    int & operator() ()
    {
        return count;
    }
    int& operator*(int num)
    {
    
    }
};

int main(int argc, char argv)
{
    try
    {
        
    }
    catch(Error &e)
        {
            e.what();
        }
    return 0;
}
