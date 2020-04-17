#include <iostream>

using namespace std;

class Money
{
    private:
    long ruble;
    int cop;
    public:
    Money ()
    { 
        ruble = 2;
        cop = 34;
    }
    Money (long in_rub, int in_cop)
    {
        ruble = in_rub;
        cop = in_cop;
    }
    void print ()
    {
        cout << ruble << "," << cop << endl; 
    }
   // ~Money ();
};

int main(int argc, char * argv[])
{
    Money koshel;
    koshel.print();
    return 0;
}
