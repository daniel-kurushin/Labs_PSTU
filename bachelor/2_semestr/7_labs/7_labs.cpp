//Духанин Алексей, лаб. 7
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int* create_arr_once(int n)
{
  int *arr = new int[n];
  for (int counter = 0; counter < n; counter++)
  {
    arr[counter] = rand() % 1000 - 500;
  }
  return arr;
}

int** create_arr_twice(int m, int n)
{
  int **arr_out = new int* [m];
  for (int counter = 0; counter < m; counter++)
  {
    arr_out[counter] = new int [n];
  }
  for (int external = 0; external < m; external++)
  {
    for (int inner = 0; inner  < n; inner++)
    {
      arr_out[external][inner] = rand() % 1000 - 500;
    }
  }
  return arr_out;
}

void print_arr_once(int* arr_in, const int n)
{
  for (int counter = 0; counter < n; counter++)
  {
    cout << arr_in[counter] << '\t';
  }
  cout << endl;
}

void print_arr_twice(int** arr_in, const int m, const int n)
{
  for (int external = 0; external < m; external++)
  {
    for (int inner = 0; inner < n; inner++)
    {
      cout << arr_in[external][inner] << '\t';
    }
    cout << endl;
  }
}

int number_even(int* arr_in, const int n)
{
  int num = 0;
  for (int counter = 0; counter < n; counter++)
  {
    if (arr_in[counter] % 2 == 0)
    {
      num++;
    }
  }
  return num;
}

int* delete_even(int* arr_in, const int n, const int num) // n - количество элементов. num -количестов чётных
{
  int nums = n - num;
  int cou = 0;
  int *arr_out = new int [nums];
  for (int counter = 0; counter < n; counter++)
  {
    if (arr_in[counter] % 2 != 0)
    {
      arr_out[cou] = arr_in[counter];
      cou++;
    }
  }
  return arr_out;
}

int** revers_odd(int** arr, const int m, const int n) // нечетные - удалять чётные, чётные - удалятьне не четные 2
{
  int tmp;
  
  for(int counter = 0; counter < n; counter++)
  {
    if((counter + 1) % 2 != 0)
    {
      
        for(int inner = 0; inner < m / 2; inner++)
        {
            
            tmp = arr[inner][counter];
            arr[inner][counter] = arr[m - inner - 1][counter];
            arr[m - inner - 1][counter] = tmp;
           
        }
    }
  }
  return arr;
}

string delete_words(string str)
{
  int how_letters = 0;
  int counter_end, counter_start, number = 0;
  how_letters = str.length();
  unsigned char letters_vowels[6] = {'a', 'i', 'o', 'y', 'e', 'u'};
  char space = ' ';

  for (int external = how_letters; external > 0; external--)
  {
    for (int inner = 0; inner < 6; inner++)
    {
      if ((str[external] == letters_vowels[inner]) and (str[external + 1] == space))
      {
        counter_end = external;
        while (!(str[external - 1] == space) or (external == 0))
        {
          if (external != 0)
          {
            external--;
          }
          else
          {
            break;
          }
        }
        counter_start = external;
        number = counter_end - counter_start;
        for (int upfront = 0; upfront < number + 1; upfront++)
        {
          for (int iter = counter_start; iter < how_letters; iter++)
          {
            str[iter] = str[iter + 1];
          }
        }
      }
    }
  }
  return str;
}

int main(int argc, char* argv[])
{

  srand(time(NULL));
  int n, m, num, n0;
  int *arr;
  int **arr_2;
  cout <<  "Работа с одномерным массивом" << '\n' << "Kоличество элементов" << endl;
  n = atoi(argv[1]);
  cout << n;
  arr = create_arr_once(n);
  print_arr_once(arr, n);
  num = number_even(arr, n);
  arr = delete_even(arr, n, num);
  n = n - num;
  print_arr_once(arr, n);

  cout << "Рaбота с двумерными массивом" << '\n' << "Kоличество строк" << endl;
  m = atoi(argv[2]);
  cout << m << endl;
  cout << "Kоличестов столбцов" << endl;
  n0 = atoi(argv[3]);
  cout << n0 <<endl;
  arr_2 = create_arr_twice(m, n0);
  print_arr_twice(arr_2, m, n0);
  arr_2 = revers_odd(arr_2, m, n0);
  //n0 % 2 == 0 ? n0 = n0 / 2 : n0 = (n0 / 2);
  cout << "После реверса" << endl;
  print_arr_twice(arr_2, m , n0);

  cout << "Операции со строками" << '\n' << "Введите строку:" << endl;
  string str;
  str = argv[4]; // будет 4
  cout << str << endl;
  str = delete_words(str);
  cout << str << endl;

  return 0;
}
