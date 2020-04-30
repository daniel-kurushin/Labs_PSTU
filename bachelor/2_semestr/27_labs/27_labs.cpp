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

int main(int argc, char* argv[])
{
    Pair x;
    cin >> x;
    cout << x;
    return 0;
}
