#include <iostream>
#include <ctime>
using namespace std;

int* create_arr_once(int n)
{
  int *arr = new int[n];
  for (int counter = 0; counter < n; counter++)
  {
    arr[counter] = rand() % 10 - 5;
  }
  return arr;
}

void print_arr_once(int* arr_in, const int n)
{
  for (int counter = 0; counter < n; counter++)
  {
    cout << arr_in[counter] << '\t';
  }
  cout << endl;
}

int * adding_sort(int *arr_in, int n)
{
    int num;
    
    int  min; 
    min = arr_in[0];
    for(int counter = 1; counter < n; counter++)
    {
        if(min > arr_in[counter])
        {
            min = arr_in[counter];
        }
    }
    int max;
    max = arr_in[0];
    for(int counter = 1; counter < n; counter++)
    {
        if(max < arr_in[counter])
        {
            max = arr_in[counter];
        }
    }
    num = max - min + 1;
    int * arr = new int [num];
    int * arr_h = new int [num];
    //cout << num << " " << min << " " << max << endl;
    for(int counter = 0; counter < num ; counter++)
    {
        arr[counter] = min;
        min++;
        //cout << arr[counter] << endl;
    }
    
    for(int external = 0; external < num; external++)
    {
        for(int inner = 0; inner < n; inner++)
        { 
            if(arr[external] == arr_in[inner])
            {
                arr_h[external]++;
            }
        }
    }
    //print_arr_once(arr_h, num);
    //print_arr_once(arr, num);
    int inner = 0;
    for(int counter = 0; counter < num; counter++)
    {
        while((arr_h[counter] > 0) and (inner < n))
        {
            arr_in[inner] = arr[counter];
            inner++;
            arr_h[counter]--;
        }
    }
    return arr_in;
}
int * fasting(int *arr_in, int left, int right)
{
  int pivot; 
  int l = left; 
  int r = right; 
  pivot = arr_in[left];
  while (left < right) 
  {
    while ((arr_in[right] >= pivot) and (left < right))
      {
          right--;
      } 
    if (left != right) 
    {
      arr_in[left] = arr_in[right]; 
      left++; 
    }
    while ((arr_in[left] <= pivot) and (left < right))
      {
          left++;
      } 
    if (left != right) 
    {
      arr_in[right] = arr_in[left]; 
      right--; 
    }
  }
  arr_in[left] = pivot; 
  pivot = left;
  left = l;
  right = r;
  if (left < pivot) 
    {
        fasting(arr_in, left, pivot - 1);
    }
  if (right > pivot)
    {
        fasting(arr_in, pivot + 1, right);
    }
    return arr_in;
}
int main(int argc, char* argv[])
{
    srand(time(NULL));
    int * arr1;
    int * arr2;
    int n = atoi(argv[1]);
    arr1 = create_arr_once(n);
    arr2 = create_arr_once(n);
    cout << "Подсчётом" << endl;
    print_arr_once(arr1, n);
    arr1 = adding_sort(arr1, n);
    print_arr_once(arr1, n);
    cout << "Быстрая" << endl;
    print_arr_once(arr2, n);
    arr2 = fasting(arr2, 0, n - 1);
    print_arr_once(arr2, n);
    return 0;
}
