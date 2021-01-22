#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int num_a, num_b, num_c, num_i, num_d, num_n;

int *arr_A = new int[num_a];
int *arr_B = new int[num_b];
int *arr_C = new int[num_c];
int *arr_I = new int[num_i];
int *arr_D = new int[num_d];

int simple_arr[11] = {0,1,2,3,5,7,9,11,13,17,19};
int negativ_arr[40];

void print_equ()
{
  for(int i = 0; i < 30; i++)
  {
    std::cout << "=";
  }
  cout << endl;
}

void make_arr_negativ()
{
  int j = -20;
  for(int i = 0; i <= 40; i++)
  {
    negativ_arr[i] = j;
    j++;
    cout << negativ_arr[i] << " ";
  }
  num_n = 40;
  cout << endl;
}

void print_arr_A()
{
  for(int i = 0; i < num_a; i++)
  {
    cout << arr_A[i] << " ";
  }
  cout << endl;
}

void print_arr_B()
{
  for(int i = 0; i < num_b; i++)
  {
    cout << arr_B[i] << " ";
  }
  cout << endl;
}

void print_arr_C()
{
  for(int i = 0; i < num_c; i++)
  {
    cout << arr_C[i] << " ";
  }
  cout << endl;
}

void print_arr_D()
{
  cout << "Полученное множество:" << endl;
  for(int i = 0; i < num_d; i++)
  {
    cout << arr_D[i] << " ";
  }
  cout << endl;
}

void input_arr_A()
{
  int state = 0;
  cout << "Введите количество элементов в множестве А(<=10):" << endl;
  cin >> num_a;
  cout << "Ввести ручками?" << endl;
  cout << "1. Да" << endl;
  cout << "2. Нет" << endl;
  cin >> state;
  if(state == 1)
  {
    cout << "Введите значения множества А:" << endl;
    for (int i = 0; i < num_a; i++)
    {
      cin >> arr_A[i];
    }
  }
  else
  {
    cout << "1. Простые числа" << endl;
    cout << "2. Натуральные числа" << endl;
    cout << "3. Положительные числа" << endl;
    cout << "4. Отрицательные числа" << endl;
    cout << "5. Четные числа" << endl;
    cout << "6. Нечетные числа" << endl;
    cin >> state;
    switch(state)
    {
      case 1:
        for(int i = 0; i < num_a; i++)
        {
          arr_A[i] = simple_arr[i];
        }
      break;
      case 2:
        for(int i = 0; i < num_a; i++)
        {
          arr_A[i] = i + 1;
        }
      break;
      case 3:
        for(int i = 0; i < num_a; i++)
        {
          arr_A[i] = i + 1;
        }
      break;
      case 4:
        for(int i = 0; i < num_a; i++)
        {
          arr_A[i] = -1 * (i + 1);
        }
      break;
      case 5:
        for(int i = 0; i < num_a; i++)
        {
          arr_A[i] = 2 * (i + 1);
        }
      break;
      case 6:
        for(int i = 0; i < num_a; i++)
        {
          if(i % 2 == 0)
          {
            arr_A[i] = i + 11;
          }
          else
          {
            arr_A[i] = i;
          }
        }
      break;
    }
    for(int i = 0; i< num_a; i++)
    {
      cout << arr_A[i] << " ";
    }
    cout << endl;
  }
}

void input_arr_B()
{
  int state = 0;
  cout << "Введите количество элементов в множестве B(<=10):" << endl;
  cin >> num_b;
  cout << "Ввести ручками?" << endl;
  cout << "1. Да" << endl;
  cout << "2. Нет" << endl;
  cin >> state;
  if(state == 1)
  {
    cout << "Введите значения множества B:" << endl;
    for (int i = 0; i < num_b; i++)
    {
      cin >> arr_B[i];
    }
  }
  else
  {
    cout << "1. Простые числа" << endl;
    cout << "2. Натуральные числа" << endl;
    cout << "3. Положительные числа" << endl;
    cout << "4. Отрицательные числа" << endl;
    cout << "5. Четные числа" << endl;
    cout << "6. Нечетные числа" << endl;
    cin >> state;
    switch(state)
    {
      case 1:
        for(int i = 0; i < num_b; i++)
        {
          arr_B[i] = simple_arr[i];
        }
      break;
      case 2:
        for(int i = 0; i < num_b; i++)
        {
          arr_B[i] = i + 1;
        }
      break;
      case 3:
        for(int i = 0; i < num_b; i++)
        {
          arr_B[i] = i + 1;
        }
      break;
      case 4:
        for(int i = 0; i < num_b; i++)
        {
          arr_B[i] = -1 * (i + 1);
        }
      break;
      case 5:
        for(int i = 0; i < num_b; i++)
        {
          arr_B[i] = 2 * (i + 1);
        }
      break;
      case 6:
        for(int i = 0; i < num_b; i++)
        {
          if(i % 2 == 0)
          {
            arr_B[i] = i + 11;
          }
          else
          {
            arr_B[i] = i;
          }
        }
      break;
    }
    for(int i = 0; i< num_b; i++)
    {
      cout << arr_B[i] << " ";
    }
    cout << endl;
  }
}

void input_arr_c()
{
  int state = 0;
  cout << "Введите количество элементов в множестве C(<=10):" << endl;
  cin >> num_c;
  cout << "Ввести ручками?" << endl;
  cout << "1. Да" << endl;
  cout << "2. Нет" << endl;
  cin >> state;
  if(state == 1)
  {
    cout << "Введите значения множества C:" << endl;
    for (int i = 0; i < num_c; i++)
    {
      cin >> arr_C[i];
    }
  }
  else
  {
    cout << "1. Простые числа" << endl;
    cout << "2. Натуральные числа" << endl;
    cout << "3. Положительные числа" << endl;
    cout << "4. Отрицательные числа" << endl;
    cout << "5. Четные числа" << endl;
    cout << "6. Нечетные числа" << endl;
    cin >> state;
    switch(state)
    {
      case 1:
        for(int i = 0; i < num_c; i++)
        {
          arr_C[i] = simple_arr[i];
        }
      break;
      case 2:
        for(int i = 0; i < num_c; i++)
        {
          arr_C[i] = i + 1;
        }
      break;
      case 3:
        for(int i = 0; i < num_c; i++)
        {
          arr_C[i] = i * 2;
        }
      break;
      case 4:
        for(int i = 0; i < num_c; i++)
        {
          arr_C[i] = -1 * (i + 1);
        }
      break;
      case 5:
        for(int i = 0; i < num_c; i++)
        {
          arr_C[i] = 2 * (i + 1);
        }
      break;
      case 6:
        for(int i = 0; i < num_c; i++)
        {
          if(i % 2 == 0)
          {
            arr_C[i] = i + 11;
          }
          else
          {
            arr_C[i] = i;
          }
        }
      break;
    }
    for(int i = 0; i< num_c; i++)
    {
      cout << arr_C[i] << " ";
    }
    cout << endl;
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
  num_d = num_a;
  for(int i = 0; i < num_a; i++)
  {
    arr_D[i] = arr_A[i];
    cout << arr_A[i] << " ";
  }
  cout << endl;
  cout << num_a << endl;
  cout << num_d << endl;
  for(int i = 0; i < num_i; i++)
  {
    cout << "udfibj" << endl;
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

void union_B_C()
{
  num_i = num_b - 1;
  for(int i = 0; i < num_b; i++)
  {
    arr_I[i] = arr_B[i];
  }
  for(int i = 0; i < num_c; i++)
  {
    int k = 1;
    for(int j = 0; j < num_b; j++)
    {
      if(arr_I[j] == arr_C[i])
      {
        k++;
      }
    }
    if(k)
    {
      arr_I[num_i] = arr_C[i];
      num_i++;
    }
  }
  for(int i = 0; i < num_i; i++)
  {
    cout <<  arr_I[i];
  }
  cout << endl;
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

void diff_A_B()
{
  num_i = 0;
  for(int i = 0; i < num_a; i++)
  {
    int count = 0;
    for(int j = 0; j < num_b; j++)
    {
      if(arr_A[i] != arr_B[j])
      {
        count++;
      }
    }
    count++;
    if(count == num_b)
    {
      arr_I[num_i] = arr_A[i];
      num_i++;
    }
  }
  for(int i = 0; i < num_i; i++)
  {
    cout << arr_I[i] << "  ";
  }
  cout << endl;
}

void diff_A_I()
{
  num_d = 0;
  for(int i = 0; i < num_a; i++)
  {
    int count = 0;
    for(int j = 0; j < num_i; j++)
    {
      if(arr_A[i] != arr_I[j])
      {
        count++;
      }
    }
    count++;
    if(count == num_i)
    {
      arr_D[num_i] = arr_A[i];
      num_d++;
    }
  }
  for(int i = 0; i < num_d; i++)
  {
    cout << arr_D[i] << "  ";
  }
  cout << endl;
}

void diff_B_C()
{
  num_i = 0;
  for(int i = 0; i < num_b; i++)
  {
    int count = 0;
    for(int j = 0; j < num_c; j++)
    {
      if(arr_B[i] != arr_C[j])
      {
        count++;
      }
    }
    count++;
    if(count == num_c)
    {
      arr_I[num_i] = arr_B[i];
      num_i++;
    }
  }
  for(int i = 0; i < num_i; i++)
  {
    cout << arr_I[i] << "  ";
  }
  cout << endl;
}

void diff_I_C()
{
  num_d = 0;
  for(int i = 0; i < num_i; i++)
  {
    int count = 0;
    for(int j = 0; j < num_c; j++)
    {
      if(arr_I[i] != arr_C[j])
      {
        count++;
      }
    }
    count++;
    if(count == num_c)
    {
      arr_D[num_d] = arr_I[i];
      num_i++;
    }
  }
  for(int i = 0; i < num_d; i++)
  {
    cout << arr_D[i] << "  ";
  }
  cout << endl;
}

void sym_diff_A_B()
{
  num_i = 0;
  for(int i = 0; i < num_a; i++)
  {
    int count = 0;
    for(int j = 0; j < num_b; j++)
    {
      if(arr_A[i] != arr_B[j])
      {
        count++;
      }
    }
    count++;
    if(count == num_b)
    {
      arr_I[num_i] = arr_A[i];
      num_i++;
    }
  }
  for(int i = 0; i < num_b; i++)
  {
    int count = 0;
    for(int j = 0; j < num_a; j++)
    {
      if(arr_B[i] != arr_A[j])
      {
        count++;
      }
    }
    count++;
    if(count == num_a)
    {
      arr_I[num_i] = arr_B[i];
      num_i++;
    }
  }
  for(int i = 0; i < num_i; i++)
  {
    cout << arr_I[i] << " ";
  }
  cout << endl;
}

void sym_diff_I_C()
{
  num_d = 0;
  for(int i = 0; i < num_i; i++)
  {
    int count = 0;
    for(int j = 0; j < num_c; j++)
    {
      if(arr_I[i] != arr_C[j])
      {
        count++;
      }
    }
    count++;
    if(count == num_c)
    {
      arr_D[num_d] = arr_I[i];
      num_d++;
    }
  }
  for(int i = 0; i < num_c; i++)
  {
    int count = 0;
    for(int j = 0; j < num_i; j++)
    {
      if(arr_C[i] != arr_I[j])
      {
        count++;
      }
    }
    count++;
    if(count == num_i)
    {
      arr_D[num_d] = arr_C[i];
      num_d++;
    }
  }
  for(int i = 0; i < num_d; i++)
  {
    cout << arr_D[i] << " ";
  }
  cout << endl;
}

void sym_diff_A_I()
{
  num_d = 0;
  for(int i = 0; i < num_a; i++)
  {
    int count = 0;
    for(int j = 0; j < num_i; j++)
    {
      if(arr_A[i] != arr_I[j])
      {
        count++;
      }
    }
    count++;
    if(count == num_i)
    {
      arr_D[num_d] = arr_A[i];
      num_d++;
    }
  }
  for(int i = 0; i < num_i; i++)
  {
    int count = 0;
    for(int j = 0; j < num_a; j++)
    {
      if(arr_I[i] != arr_A[j])
      {
        count++;
      }
    }
    count++;
    if(count == num_a)
    {
      arr_D[num_d] = arr_I[i];
      num_d++;
    }
  }
  for(int i = 0; i < num_d; i++)
  {
    cout << arr_D[i] << " ";
  }
  cout << endl;
}

void negativ_A()
{
  int num_prom = 40;
  int arr_prom[40];
  for(int i = 0; i <= num_n; i++)
  {
    arr_prom[i] = negativ_arr[i];
  }
  for(int i = 0; i < num_a; i++)
  {
    for(int j = 0; j <= num_prom; j++)
    {
      if(arr_A[i] == arr_prom[j])
      {
        int k = j;
        while(k <= num_prom)
        {
          arr_prom[k] = arr_prom[k + 1];
          k++;
        }
      }
    }
  }
  num_prom = num_prom - num_a;
  for(int i = 0; i <= num_prom; i++)
  {
    //cout << arr_prom[i] << " ";
    arr_A[i] = arr_prom[i];
  }
  cout << endl;
  num_a = num_prom + 1;
  print_arr_A();
}

void negativ_B()
{
  int num_prom = 40;
  int arr_prom[40];
  for(int i = 0; i <= num_n; i++)
  {
    arr_prom[i] = negativ_arr[i];
  }
  for(int i = 0; i < num_b; i++)
  {
    for(int j = 0; j <= num_prom; j++)
    {
      if(arr_B[i] == arr_prom[j])
      {
        int k = j;
        while(k <= num_prom)
        {
          arr_prom[k] = arr_prom[k + 1];
          k++;
        }
      }
    }
  }
  num_prom = num_prom - num_b;
  for(int i = 0; i <= num_prom; i++)
  {
    //cout << arr_prom[i] << " ";
    arr_B[i] = arr_prom[i];
  }
  cout << endl;
  num_b = num_prom + 1;
  print_arr_B();
}

void negativ_C()
{
  int num_prom = 40;
  int arr_prom[40];
  for(int i = 0; i <= num_n; i++)
  {
    arr_prom[i] = negativ_arr[i];
  }
  for(int i = 0; i < num_c; i++)
  {
    for(int j = 0; j <= num_prom; j++)
    {
      if(arr_C[i] == arr_prom[j])
      {
        int k = j;
        while(k <= num_prom)
        {
          arr_prom[k] = arr_prom[k + 1];
          k++;
        }
      }
    }
  }
  num_prom = num_prom - num_c;
  for(int i = 0; i <= num_prom; i++)
  {
    //cout << arr_prom[i] << " ";
    arr_C[i] = arr_prom[i];
  }
  cout << endl;
  num_c = num_prom + 1;
  print_arr_C();
}

void negativ_D()
{
  int num_prom = 40;
  int arr_prom[40];
  for(int i = 0; i <= num_n; i++)
  {
    arr_prom[i] = negativ_arr[i];
  }
  for(int i = 0; i < num_d; i++)
  {
    for(int j = 0; j <= num_prom; j++)
    {
      if(arr_D[i] == arr_prom[j])
      {
        int k = j;
        while(k <= num_prom)
        {
          arr_prom[k] = arr_prom[k + 1];
          k++;
        }
      }
    }
  }
  num_prom = num_prom - num_d;
  for(int i = 0; i <= num_prom; i++)
  {
    //cout << arr_prom[i] << " ";
    arr_D[i] = arr_prom[i];
  }
  cout << endl;
  num_d = num_prom + 1;
  print_arr_D();
}

void chose_set_do()
{
  int state, chose_A_B, chose_B_C;
  cout << "Выполнить опецию отрицания?" <<  endl;
  cout << "1. Да" << endl;
  cout << "2. Нет" <<endl;
  cin >> state;
  if(state == 1)
  {
    cout << "Над каким множеством выполнить отрицание?" << endl;
    cout << "1. А" << endl;
    cout << "2. В" << endl;
    cout << "3. С" << endl;
    cin >> state;
    switch(state)
    {
      case 1:
      negativ_A();
      print_equ();
      chose_set_do();
      break;
      case 2:
      negativ_B();
      print_equ();
      chose_set_do();
      break;
      case 3:
      negativ_C();
      print_equ();
      chose_set_do();
      break;
    }
  }
  else
  {
    cout << "Операции над множествами:" << endl;
    cout << "1. Объединение" << endl;
    cout << "2. Пересечение" << endl;
    cout << "3. Разность" << endl;
    cout << "4. Симметрическая разность" << endl;

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
    else if((chose_A_B == 3) and (chose_B_C == 1))
    {
      union_B_C();
      diff_A_I();
    }
    else if((chose_A_B == 3) and (chose_B_C == 2))
    {
      crossing_B_C();
      diff_A_I();
    }
    else if((chose_A_B == 3) and (chose_B_C == 3))
    {
      diff_A_B();
      diff_I_C();
    }
    else if((chose_A_B == 3) and (chose_B_C == 4))
    {
      diff_A_B();
      sym_diff_I_C();
    }
    else if((chose_A_B == 4) and (chose_B_C == 1))
    {
      union_B_C();
      sym_diff_A_I();
    }
    else if((chose_A_B == 4) and (chose_B_C == 2))
    {
      crossing_B_C();
      sym_diff_A_I();
    }
    else if((chose_A_B == 4) and (chose_B_C == 3))
    {
      diff_B_C();
      sym_diff_A_I();
    }
    else if((chose_A_B == 4) and (chose_B_C == 4))
    {
      sym_diff_A_B();
      sym_diff_I_C();
    }
  }
}


int main()
{
  srand(time(NULL));
  make_arr_negativ();
  input_arr_A();
  print_equ();
  input_arr_B();
  print_equ();
  input_arr_c();
  print_equ();
  chose_set_do();
  print_arr_D();
  return 0;
}
