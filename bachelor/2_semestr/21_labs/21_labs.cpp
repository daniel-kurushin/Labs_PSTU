#include <iostream>
#include <string>

using namespace std;

class Person
{
    public:
    string name;
    int age;
    Person ()
    {
        name = "Ivan Ivanov";
        age = 99;
    }
    
    string change_name (string new_name)
    {
        name = new_name;
        return name;
    }
    
    int change_age (int new_age)
    {
        age = new_age;
        return age;
    } 
};

class Teacher : public Person
{
    private:
        string sub;
        int hours;
    public:
        Teacher()
        {
            sub = "Matan";
            hours = 9999;
        }
        Teacher(string in_sub, int in_hours)
        {
            sub = in_sub;
            hours = in_hours;
        }
        void print()
        {
            cout << name << " : " << age << " : " << sub << " : " <<  hours << endl;
        }
        
        string change_sub(string new_sub)
        {
            sub = new_sub;
            return sub;
        }
        int change_hours(int new_hours)
        {
            hours = new_hours;
            return hours;
        }
};

int main(int argc, char * argv[])
{
    Teacher pstu;
    pstu.change_name("Greg House");
    pstu.change_sub("Chemistry");
    pstu.change_age(40);
    pstu.change_hours(2);
    pstu.print();
    return 0;
}
