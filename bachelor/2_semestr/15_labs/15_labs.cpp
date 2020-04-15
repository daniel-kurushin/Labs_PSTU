#include <iostream>
#include <stack>
#include <ctime>
using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    
    stack <int> my_stack;
    stack <int> ugl_stack;
    stack <int> out_stack;
    int tmp, elem;
    for(int counter = 0; counter < 10; counter++)
    {
        tmp = rand() % 100 - 50;
        my_stack.push(tmp);
        cout << tmp << '\t';
    }
    cout << endl;
    while(!my_stack.empty())
    {
        elem = my_stack.top();
        my_stack.pop();
        ugl_stack.push(elem);
        while(!my_stack.empty())
        {
            tmp = my_stack.top();
            my_stack.pop();
            if(tmp > elem)
            {
                elem = tmp;
            }
            ugl_stack.push(tmp);
        }
        while(!ugl_stack.empty())
        {
            tmp = ugl_stack.top();
            ugl_stack.pop();
            if(tmp == elem) 
            { 
                out_stack.push(tmp);
            }
            else
            {
                my_stack.push(tmp);
            }
        }
    }
    while(!out_stack.empty())
    {
        cout << out_stack.top() << '\t';
        out_stack.pop();
    }
    cout << endl;
    return 0;
}
