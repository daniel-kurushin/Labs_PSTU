//Духанин Алексей, лаб. 23
#include <iostream>

using namespace std;

class Plur
{
    private:
    int length;
    int * data;
    public:
    Plur()
    {
        length = 0;
        data = NULL;
    }
    Plur(int in_length)
    {
        length = in_length;
        data = new int [length];
    }
    ~Plur()
    {
        delete[] data;
    }
    int& operator[](int index)
    {
        return data[index];
    }
    Plur operator*(Plur &in_plur)
    {
        for(int counter = 0; counter < length; counter++)
        {
            if(data[counter] == in_plur[counter])
            {
                cout << data[counter] <<'\t';
            }
        }
        return 0;
    }
};

int main(int argc, char* argv[])
{
    Plur plur_one(15);
    Plur plur_two(15);
    for(int counter = 0; counter < 15; counter++)
    {
        plur_one[counter] = counter;
        plur_two[counter] = counter;
    }
    plur_one * plur_two;
    cout << endl;
    return 0;
}
