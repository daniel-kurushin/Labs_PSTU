#include <iostream>
#include <cmath>

using namespace std;

int num_a, num_b, num_c, num_i, num_d;

int *arr_A = new int[num_a];
int *arr_B = new int[num_b];
int *arr_C = new int[num_c];
int *arr_I = new int[num_i];
int *arr_D = new int[num_d];

void input_arr_A()
{
  cout << "Введите количество элементов в множестве А:" << endl;
  cin >> num_a;
  cout << "Введите значения множества А:" << endl;
  for (int i = 0; i < num_a; i++)
  {
    cin >> arr_A[i];
  }
}

void input_arr_B()
{
  cout << "Введите количество элементов в множестве b:" << endl;
  cin >> num_b;
  cout << "Введите значения множества B:" << endl;
  for (int i = 0; i < num_b; i++)
  {
    cin >> arr_B[i];
  }
}

void input_arr_c()
{
  cout << "Введите количество элементов в множестве c:" << endl;
  cin >> num_c;
  cout << "Введите значения множества C:" << endl;
  for (int i = 0; i < num_c; i++)
  {
    cin >> arr_C[i];
  }
}

void union_A_B()
{
  num_i = num_a - 1;
  for(int i = 0; i < num_a; i++)
  {
    arr_I[i] = arr_A[i];
  }
  for(int i = 0; i < num_b; i++)
  {
    int k = 1;
    for(int j = 0; j < num_a; j++)
    {
      if(arr_I[j] == arr_B[i])
      {
        k++;
      }
    }
    if(k)
    {
      arr_I[num_i] = arr_B[i];
      num_i++;
    }
  }
  for(int i = 0; i < num_i; i++)
  {
    cout <<  arr_I[i];
  }
  cout << endl;
}

void union_A_I()
{
  num_d = num_a - 1;
  for(int i = 0; i < num_a; i++)
  {
    arr_D[i] = arr_A[i];
  }
  for(int i = 0; i < num_i; i++)
  {
    int k = 1;
    for(int j = 0; j < num_a; j++)
    {
      if(arr_D[j] == arr_I[i])
      {
        k++;
      }
    }
    if(k)
    {
      arr_D[num_d] = arr_I[i];
      num_d++;
    }
  }
}

void union_I_C()
{
  num_d = num_i - 1;
  for(int i = 0; i < num_i; i++)
  {
    arr_D[i] = arr_I[i];
  }
  for(int i = 0; i < num_c; i++)
  {
    int k = 1;
    for(int j = 0; j < num_i; j++)
    {
      if(arr_D[j] == arr_C[i])
      {
        k++;
      }
    }
    if(k)
    {
      arr_D[num_d] = arr_C[i];
      num_d++;
    }
  }
}

void crossing_A_B()
{
  num_i = 0;
  for(int i = 0; i < num_a; i++)
  {
    for(int j = 0; j < num_b; j++)
    {
      if(arr_A[i] == arr_B[j])
      {
        arr_I[num_i] = arr_A[i];
        num_i++;
      }
    }
  }
}

void crossing_B_C()
{
  num_i = 0;
  for(int i = 0; i < num_b; i++)
  {
    for(int j = 0; j < num_c; j++)
    {
      if(arr_B[i] == arr_C[j])
      {
        arr_I[num_i] = arr_B[i];
        num_i++;
      }
    }
  }
}

void crossing_I_C()
{
  num_d = 0;
  for(int i = 0; i < num_i; i++)
  {
    for(int j = 0; j < num_c; j++)
    {
      if(arr_I[i] == arr_C[j])
      {
        arr_D[num_d] = arr_B[i];
        num_d++;
      }
    }
  }
}

void diff_I_C()
{
  num_d = num_i;
  for(int i = 0; i < num_i; i++)
  {
    arr_D[i] = arr_I[i];
  }
  for(int i = 0; i < num_c; i++)
  {
    for(int j = 0; j < num_i; j++)
    {
      if(arr_D[j] == arr_C[i])
      {
        for(int k = j; k < num_d; k++)
        {
          arr_D[k] = arr_D[k + 2];
        }
        num_d = num_d - 2;
      }
      else
      {
        arr_D[num_d] = arr_C[i];
        num_d++;
      }
    }
  }
}

void sym_diff_I_C()
{

}

void chose_set_do()
{
  cout << "Операции над множествами:" << endl;
  cout << "1. Объединение" << endl;
  cout << "2. Пересечение" << endl;
  cout << "3. Разность" << endl;
  cout << "4. Симметрическая разность" << endl;
  cout << "5. Отрицание" << endl;
  int chose_A_B, chose_B_C;
  cout << "Выберете отперацию над множествами А и В" << endl;
  cin >> chose_A_B;
  cout << "Выберете отперацию над множествами В и С" << endl;
  cin >> chose_B_C;
  if((chose_A_B == 1) and (chose_B_C == 1))
  {
    union_A_B();
    union_I_C();
  }
  else if ((chose_A_B == 1) and (chose_B_C == 2))
  {
    crossing_B_C();
    union_A_I();
  }
  else if ((chose_A_B == 1) and (chose_B_C == 3))
  {
    union_A_B();
    diff_I_C();
  }
  else if ((chose_A_B == 1) and (chose_B_C == 4))
  {
    union_A_B();
    sym_diff_I_C();
  }
  else if((chose_A_B == 2) and (chose_B_C == 1))
  {
    crossing_A_B();
    union_I_C();
  }
  else if((chose_A_B == 2) and (chose_B_C == 2))
  {
    crossing_A_B();
    crossing_I_C();
  }
  else if((chose_A_B == 2) and (chose_B_C == 3))
  {
    crossing_A_B();
    diff_I_C();
  }
  else if((chose_A_B == 2) and (chose_B_C == 4))
  {
    crossing_A_B();
    sym_diff_I_C();
  }
}

void print_arr_D()
{
  cout << "Полученное множество:" << endl;
  for(int i = 0; i < num_d; i++)
  {
    cout << arr_D[i] << '\t';
  }
  cout << endl;
}

int main()
{
  input_arr_A();
  input_arr_B();
  input_arr_c();
  chose_set_do();
  print_arr_D();
  return 0;
}
