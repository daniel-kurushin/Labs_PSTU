#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define CREATE_ONCE  1
#define PRINT_ONCE   2
#define ADDING       3
#define CREATE_TWICE 4
#define PRINT_TWICE  5
#define DELETE       6
#define EXIT         7

int* create_arr_once(int n)
{
  int *arr = new int [n];
  for (int counter = 0; counter < n; counter++)
  {
    arr[counter] = rand() % 1000 - 500;
  }
  return arr;
}

void print_arr_once(int* arr_in, const int n)
{
  for (int counter = 0; counter < n; counter++)
  {
    cout <<  arr_in[counter] << '\t';
  }
  cout << endl;
}

int* adding(int* arr_in, const int num, const int n)
{
  int nums = n + num;
  int *arr_out = new int [nums];
  for (int counter = 0; counter < num; counter++)
  {
    arr_out[counter] = arr_in[counter];
  }
  for (int counter = num; counter < nums; counter++)
  {
    arr_out[counter] = rand() % 1000 - 500;
  }
  return arr_out;
}

int** create_arr_twice(int m, int n)
{
  int** arr = new int* [m];
  for (int counter = 0; counter < m; counter++)
  {
    arr[counter] = new int [n];
  }

  for (int external = 0; external < m; external++)
  {
    for (int inner = 0; inner < n; inner++)
    {
      arr[external][inner] = rand() % 1000 - 500;
    }
  }
  return arr;
}

void print_arr_twice(int** arr, const int m, const int n)
{
  for (int external = 0; external < m; external++)
  {
    for (int inner = 0; inner < n; inner++)
    {
      cout << arr[external][inner] << '\t';
    }
    cout << '\n';
  }
}

void del_k1_k2(int** arr, const int num, const int l, const int a, const int k1)
{
  for (int upfront = 0; upfront < num; upfront++)
  {
    for (int external = 0; external < l; external++)
    {
      for (int inner = k1; inner < a; inner++)
      {
        arr[external][inner] = arr[external][inner + 1];
      }
    }
  }
}

int main()
{
  srand(time(NULL));
  srand(time(NULL));
  int state = 0;
  int k, num, nums, n, m, k1, k2 = 0;
  int *arr;
  int **arr_;
  do
  {
    cout << "1.Создать одномерный массив" << endl;
    cout << "2.Печать одномерного массива" << endl;
    cout << "3.Добавить в массив элементы" << endl;
    cout << "4.Создать двумерный массив" << endl;
    cout << "5.Печать двумерного массива" << endl;
    cout << "6.Удалить столбцы" << endl;
    cout << "7.Выход" << endl;
    cin >> state;
    switch (state)
    {
      case CREATE_ONCE:
        cout << "Введите нужное количество элементов:";
        cin >> num;
        arr = create_arr_once(num);
        break;

      case PRINT_ONCE:
        print_arr_once(arr, num);
        break;

      case ADDING:
        cout << "Введите количество элементов котрые хотите добавить: ";
        cin >> k;
        arr = adding(arr, num, k);
        num += k;
        break;

      case CREATE_TWICE:
        cout << "Введите количество строк:" << '\n';
        cin >> m;
        cout << "Введите количество столбцов" << endl;
        cin >> n;
        arr_ = create_arr_twice(m, n);
        break;

      case PRINT_TWICE:
        print_arr_twice(arr_, m, n);
        break;

      case DELETE:
        cout << "ВВедите к1" << endl;
        cin >> k1;
        cout << "ВВедите к2" << endl;
        cin >> k2;
        if ( k2 >= n)
        {
          n = n - k1;
        }
        else
        {
          nums = k2 - k1 + 1;
          del_k1_k2(arr_, nums, m, n, k1);

          n = n - nums;
        }
        break;
    }
  } while (state != EXIT);
  return 0;
}
