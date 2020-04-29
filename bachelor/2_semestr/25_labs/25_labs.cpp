//Духанин Алексей, лаб 25
#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd     = 1;
const int cmDel     = 2;
const int cmGet     = 3;
const int cmShow    = 4;
const int cmMake    = 6;
const int cmQuit    = 101;

struct TEvent
{
    int what;
    union
    {
        int command;
        {
            int massage;
            int a;
        };
    };
};

class Printing
{
    public:
    
    virtual void print()
    {
        
    }
    virtual void chenge()
    {
        
    }
};

class Books : public Printing
{
    public:
    string title;
    string name;
    Books()
    {
        title = "Chemistry";
        name = "Greg House";
    }
    Books(string in_title, string in_name)
    {
        title = in_title;
        name = in_name;
    }
    virtual void print()
    {
        cout << name << " - " << title << endl;
    }
    void chenge()
    {
        cout << "Title? "; 
        cin.ignore(32767, '\n');
        getline(cin, title);
        cout << "Name?";
        cin.ignore(32767, '\n');
        getline(cin, name);
    }
    void change_title(string in_title)
    {
        title = in_title;
    }
    void change_name(string in_name)
    {
        name = in_name;
    }
};

class Magazin : public Books
{
    public:
    int pages;
    Magazin (string in_title, string in_name, int in_pages)
    {
        title = in_title;
        name = in_name;
        pages = in_pages;
    }
    Magazin ()
    {
        title = "ADFR";
        name = "Ivan Invanov";
        pages = 53; 
    }
    void chenge()
    {
        cout << "Title? "; 
        cin.ignore(32767, '\n');
        getline(cin, title);
        cout << "Name? ";
        cin.ignore(32767, '\n');
        getline(cin, name);
        cout << "Pages? ";
        cin >> pages;
    }
    void print()
    {
        cout << name << " - " << title << " / " << pages << endl;
    }
    void change_pages(int in_pages)
    { 
        pages = in_pages;
    }
};

class List
{
    private:
    struct list
    {
        Printing * data;
        struct list * next;
    };
    list *head;
    int choice;
    public:
    List()
    {
        head = NULL;
    }
    void add()
    {
        list * p = new list;
        cout << "1.Books\n2.Magazin" << endl;
        cin >> choice;
        if(choice)
        {
            Books * a = new (Books);
            a -> chenge();
            p -> data = a;
            p -> next = head;
            head = p;
        }
        else
        {
            Magazin * a = new (Magazin);
            a -> chenge();
            p -> data = a;
            p -> next = head;
            head = p;
        }
    }
    void print()
    {
        list  * p = head;
        while(p != NULL)
        {
            p -> data -> print();
            p = p -> next;
        }
    }
    void del()
    {
        int num;
        cout << "num elem? ";
        cin >> num;
        list * tmp = head;
        for(int counter = 0; counter < num; counter++)
        {
            tmp = tmp -> next;
        }
        list * p = head;
        for(int i = 0; i < num + 1; i++)
        {
            p = p -> next;
        }
        while(p != NULL)
        {
            tmp -> data = p -> data;
            tmp = tmp -> next;
            p = p -> next;
        }
        head = tmp;
    }
};

class Dialog : public List
{
    public:
    Dialog(void)
    {
        endstate = 0;
    }
    void getevent(TEvent &event)
    {
        string OpInt = "+-szq";
        string s;
        string param;
        char code;
        cout << '>';
        cin >> s;
        code = s[0];
        if(OpInt.find(code) >= 0)
        {
            event.what = evMessage;
            switch(code)
            {
                case '+':
                    event.command = cmAdd;
                break;
                case '-':
                    event.command = cmDel;
                break;
                case 's':
                    event.command = cmShow;
                break;
                case 'z':
                    event.command = cmMake;
                break;
                case 'q':
                    event.command = cmQuit;
                break;
            }
            if(s.length() > 1)
            {
                param  = s.substr(1, s.length() - 1);
                int tmp = atoi(param.c_str());
                event.a = tmp;
            }
        }
        else
        {
            event.what = evNothing;
        }
    }
    int execute()
    {
        TEvent event;
        do
        {
            endstate = 0;
            getevent(event);
            handleevent(event);
            
        }while(!valid());
        return endstate;
    }
    int valid()
    {
        if(endstate == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    int handleevent(TEvent &event)
    {
        if(event.what == evMessage)
        {
            List one;
            switch(event.command)
            {
                case cmMake:
                {
                    
                    event.command = 0;
                }
                break;
                
                case cmAdd:
                {
                    one.add();
                    event.command = 0;
                }
                break;
                
                case cmDel:
                {
                    one.del();
                    event.command = 0;
                }
                break;
                
                case cmShow:
                {
                    one.print();
                    event.command = 0;
                }
                break;
                
                case cmQuit:
                {
                    event.command = 0;
                    return 0;
                }
                break;
            }
        }
    }
    protected:
    int endstate;
};

int main(int argc, char* argv[])
{
    Dialog first;
    while(!first.execute());
    return 0;
}
