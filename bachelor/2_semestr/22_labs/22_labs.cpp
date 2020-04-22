#include <iostream>

using namespace std;

class Money
{
    private:
    long ruble, out_ruble;
    int cop, out_cop;
    public:
    //long ruble, out_ruble;
    //int cop, out_cop;
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
    friend void division(Money &in_money_one, Money &in_money_two);
    void fractional(Money &in_koshel, int num)
    {
        in_koshel.ruble = ruble * num;
    }
   // ~Money ();
};

void division(Money &in_money_one, Money &in_money_two)
{
    in_money_one.cop = 2;
    in_money_two.cop = 2;
}

int main(int argc, char * argv[])
{
    Money koshel1(4, 44);
    Money koshel2(5, 45);
    koshel1.print();
    koshel2.print();
    //division(koshel1, koshel2);
    koshel1.fractional(koshel2, 4);
    koshel1.print();
    koshel2.print();
    return 0;
}
