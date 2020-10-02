#include <iostream>
#include <cmath>

using namespace std;

int arr_A[100];
int arr_B[100];
int arr_C[100];

int count_a = 0;
int count_b = 0;
int count_c = 0;

void print_arr_C()
{
  cout << "print" << endl;
  int i = 0;
  while(count_c != i)
  {
    cout << arr_C[i] << "\t";
    i++;
  }
  cout << endl;
}

void union_set()
{
  int repeat = 0;
  for(int i = 0; i < count_a; i++)
  {
    for(int j = 0; j < count_b; j++)
    {
      if(arr_A[i] == arr_B[j])
      {
        cout << arr_A[i] << "\t" << arr_B[j] << endl;
        repeat = 1;
      }
    }
  }
  cout << "union_set" << "a" << count_a << "b" << count_b << endl;
  if(!repeat)
  {
    while(arr_A[count_c - 1] == -1)
    {
      arr_C[count_c] = arr_A[count_c];
      count_c++;
    }
    count_c --;
    int i = 0;
    while(arr_B[i - 1] == -1)
    {
      arr_C[count_c] = arr_B[i];
      i++;
      count_c++;
    }
    i--;
    count_c--;
    print_arr_C();
  }
}

int main()
{
  int state = 0;
  cin >> state;
  cout << "dsvbiu" << endl;
  switch(state)
  {
    case 1:
    cout << "sdovin" << endl;
      int i = 0;
      while(arr_A[i-1] != -1)
      {
        cin >> arr_A[i];
        i++;
        count_a++;
      }
      count_a--;
      i = 0;
      cout << "sdnovk" << endl;
      while(arr_B[i-1] != -1)
      {
        cin >> arr_B[i];
        i++;
        count_b++;
      }
      count_b--;
      union_set();
    break;
  }
  return 0;
}
