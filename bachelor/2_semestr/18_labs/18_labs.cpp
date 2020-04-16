#include <iostream>
#include <ctime>
#include <string>
#define NUMBER  0
#define NAME    1
#define SURNAME 2
#define PADRE   3
#define DATE    4
#define ADRESS  5

using namespace std;

char literas [27] = {'q', 'w', 'e',  'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
char numbers [10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

string create_name()
{
    string name;
    for(int counter = 0; counter < 8; counter++)
    {
        name += literas[rand() % 27];
    }
    return name;
}

string create_surname()
{
    string surname;
    for(int counter = 0; counter < 8; counter++)
    {
        surname += literas[rand() % 27];
    }
    return surname;
}
string create_padre()
{
    string padre;
    for(int counter = 0; counter < 8; counter++)
    {
        padre += literas[rand() % 27];
    }
    return padre;
}
string create_date()
{
    string date;
    for(int counter = 0; counter < 8; counter++)
    {
        date += numbers[rand() % 10];
    }
    return date;
}
string create_adress()
{
    string adress;
    for(int counter = 0; counter < 10; counter++)
    {
        adress += literas[rand() % 27];
    }
    return adress;
}
void create_data(string arr[100][6])
{
    for(int counter = 0; counter < 100; counter ++)
    {
        arr[counter][NAME]    = create_name();
        arr[counter][SURNAME] = create_surname();
        arr[counter][PADRE]   = create_padre();
        arr[counter][DATE]    = create_date();
        arr[counter][ADRESS]  = create_adress();
        cout << arr[counter][NAME] << ' ' << arr[counter][SURNAME] << ' ' << arr[counter][PADRE] << ' ' << arr[counter][DATE] << ' ' << arr[counter][ADRESS] << endl;
    }
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    string  arr[100][6];
    string str, end;
    string main;
    //main = name();
    end  = "bbbbb";
    str = create_name() + ' ' + create_surname() + ' ' + create_padre();
    //cout << str <<" " << create_date() << " " << create_adress() << endl;
    create_data(arr);
    return 0;
}
