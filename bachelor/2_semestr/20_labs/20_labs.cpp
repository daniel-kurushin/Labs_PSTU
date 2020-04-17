#include <iostream>
#define INIT 0
#define IN   1
#define GET  2
#define EXIT 3
using namespace std;

class fir
{
    private:
    int cel;
    double drob;
    
    public:
    int multiply(int k)
    {
        return cel * k;
    }
    double multiply(double k)
    {
        return drob * k;
    }
    void set_num(int num)
    {
        cel = num;
    }
    void set_num(double num)
    {
        drob = num;
    }
};

class cash_mach
{
    private:
    int index_num;
    double ost_sum;
    double max_sum;
    
    public:
    cash_mach(double ost, double max)
    {
        ost_sum = ost;
        max_sum = max;
    }
    void set_user(int index)
    {
        index_num = index;
    }
    int get_cash(int index, int num)
    {
        cout << index_num << '\t' << ost_sum << endl;
        if(index_num == index)
        {
            if(num <= max_sum)
            {
                if(num <= ost_sum)
                {
                    ost_sum -= num;
                    cout << ost_sum << endl;
                    return 3;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    int in_cash(int index, int num)
    {
        if(index_num == index)
        {
            ost_sum += num;
            cout << ost_sum << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main(int argc, char * argv[])
{
    fir firstlab;
    int num = 5;
    double n = 0.5;
    firstlab.set_num(num);
    firstlab.set_num(n);
    num = firstlab.multiply(2);
    n = firstlab.multiply(2.0);
    cout << num << '\t' << n << endl;
    
    cash_mach atm1(400, 40);
   
    atm1.set_user(12);

    bool i = 1;
    int tmp, sum;
    int state = 0;
    while(i)
    {
        switch(state)
        {
            case INIT:
                cout << "1. Снять \n 2. Положить ";
                cin >> state;
            break;
            
            case IN:
                cout << "index, sum" << endl;
                cin >> tmp;
                cin >> sum;
                i = atm1.get_cash(tmp, sum);
                cout << "1. Снять \n 2.Положить \n 3.Выход ";
                cin >> state;
            break;
            
            case GET:
                cout << "index, sum" << endl;
                cin >> tmp;
                cin >> sum;
                i = atm1.in_cash(tmp, sum);
                cout << "1. Снять \n 2.Положить \n 3.Выход ";
                cin >> state;
            break;
            
            case EXIT:
            i = 0;
            break;
        }
    } 
    return 0;
}
