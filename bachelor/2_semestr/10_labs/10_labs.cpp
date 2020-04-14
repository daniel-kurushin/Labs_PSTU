//Духанин Алуксей, лаб. 10
#include <iostream>
#include <stdarg.h>
#include <cstring>
using namespace std;

const int N = 1;
char surname_arr[N][10];
char group_arr[N][13];
int curse_arr[N];

void init(int i, const char* surname = "Духанин", const char* group = "ивт-19-1б", int curse = 1)
{
 strcpy(surname_arr[i], surname);
 strcpy(group_arr[i], group);
 curse_arr[i] = curse;
}

void print7_1()
{
 cout << "Фамилия: " << surname_arr[0] << '\n' << "Группа: ";
 for(int counter = 0; counter < 14; counter++)
 {
  cout << group_arr[0][counter];
 }
 cout << endl;

 cout << "Курс: " << curse_arr[0] << endl;
}

double s_sum_fun(double k, ...)
{
 double s = 0.0;
 double sum = 0.0;
 va_list p;
 va_start(p, k);
 for(int counter = 0; counter < k; counter++)
 {
  s += va_arg(p, double);
 }
 va_end(p);
 sum = s / k;
 return sum;
}

double s_sum_fun(int k, ...)
{
 double s = 0.0;
 float sum = 0.0;
 va_list p;
 va_start(p, k);
 for(int counter = 0; counter < k; counter++)
 {
  s += va_arg(p, int);
 }
 va_end(p);
 sum = s / k;
 return sum;
}

int maxs(int* arr, int n)
{
 int max = arr[0];
 int index = 0;
 for(int counter = 0; counter < 3; counter++)
 {
  if(max < arr[counter])
  {
   max = arr[counter];
   index = counter;
  }
  cout << arr[counter] << '\t';
 }
 return index;
}

float maxs(float* arr, int n)
{
 float max = 0.0;
 int index = 0;
 max = arr[0];
 for(int counter = 0; counter < n; counter++)
 {
  if(max < arr[counter])
  {
   max = arr[counter];
   index = counter;
  }
  cout << arr[counter] << '\t';  
 }
 return index;
}

template < typename T >

T max_index(T* arr, int n)
{
 T max = 0.0;
 T index = 0;
 max = arr[0];
 for(int counter = 0; counter < n; counter++)
 {
  if(max < arr[counter])
  {
   max = arr[counter];
   index = counter;
  }
  cout << arr[counter] << '\t';    
 }
 return index;
}

int main(int argc, char* argv[])
{
 // 7.1 
 
 cout << "Умалчиваемые параметры" << endl;
 init(0);
 print7_1();
 
 //7.2
 
 double s_sum = 0;
 cout << "Переменные параметры" << endl;
 
 s_sum = s_sum_fun(6, 4, 6, 3, 5, 8, 3);
 cout << "Последовательность: 4, 6, 3, 5, 8, 4" << endl;
 cout << s_sum << endl;
 
 s_sum = s_sum_fun(8.0, 3.6, 19.89, 52.78, 37.12, 15.5, 21.04, 11.23, 199.1);
 cout << "Последовательность: 3.6, 19.89, 52.78, 37.12, 15.5, 21.04, 11.23, 199.1" << endl;
 cout << s_sum << endl;
 
 s_sum = s_sum_fun(4.0, 16.26, 555.8, 55.58, 784.58);
 cout << "Последовательность: 16.26, 555.8, 55.58, 784.58" << endl;
 cout  << s_sum << endl; 
 
 //7.3
 
 int arr1[3] = {1, 2, 7};
 float arr2[3] = {4.89, 9.9, 2.47};
 int index = 0;
 int nums = 3;
 
 cout << "Перегрузка" << endl;
 
 index = maxs(arr1, nums);
 cout << endl << index << endl; 
 
 index = maxs(arr2, nums);
 cout << endl << index << endl;
 
 cout << "Шаблон" << endl;
 
 index = max_index(arr1, nums);
 cout << endl << index << endl;
 
 index = max_index(arr2, nums);
 cout << endl << index << endl;
  
 return 0;
}
