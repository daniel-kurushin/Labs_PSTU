#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>

using namespace std;

class Pair
{
    public:
    int first;
    double second;
    public:
    Pair()
    {
        first = 4;
        second = 0.04;
    }
    Pair(int in_first, double in_second)
    {
        first  = in_first;
        second = in_second;
    }
    int operator==(Pair &in_pair)
    {
        if((first == in_pair.first) and (second == in_pair.second))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int operator!=(Pair &in_pair)
    {
        if((first == in_pair.first) and (second == in_pair.second))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

ostream& operator<<(ostream &out, Pair &in_pair)
{
    out << in_pair.first << " : " << in_pair.second << '\n'; 
    return out;
}

istream& operator>>(istream& in, Pair &in_pair)
{
    cout << "first? ";
    in >> in_pair.first;
    cout << "second& ";
    in >> in_pair.second;
    return in;
}

fstream& operator >>(fstream& fin, Pair &in_pair)
{
    fin >> in_pair.first;
    fin >> in_pair.second;
    return fin;
}

fstream& operator << (fstream& fout, Pair &in_pair)
{
    fout << in_pair.first << " : " << in_pair.second << '\n';
    return fout;
}

int make_file(const char* file_name)
{
    fstream stream(file_name, ios::out|ios::trunc);
    if(!stream)
    {
        return 2;
    }
    Pair one;
    int num;
    cin >> num;
    for(int counter = 0; counter < num; counter++)
    {
        cin >> one;
        stream << one << '\n';
    }
    stream.close();
    return num;
}

int main(int argc, char* argv[])
{
    Pair x;
    int state, eror = 1;
    char file_name[30];
    while(state)
    {
        cout << "file? ";
        cin >> file_name;
        eror = make_file(file_name);
        if(eror == 2)
        {
            cout << "cant make file, exit - 0, cont - 1 ";
        }
        else
        {
            cout << "exit - 0, cont - 1 ";
        }
        cin >> state;
    }
    return 0;
}
