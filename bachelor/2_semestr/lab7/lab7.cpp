//лаба 7 с решением нелинейныых уравнений
// 3x-4lnx- 5 = 0;
// df = 3 - 4/x
// [2;4]
// 3.2300
#include <iostream>
#include <cmath>
using namespace std;

int sign(double f)
{
  if (f < 0.0)
  {
    return 1;
  }
  else if (f >= 0.0)
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

double function(double x)
{
  return   ((4 * log(x) + 5) / 3);
}

double func_orig(double x)
{
  return (3 * x - 4 * log(x) - 5);
}

double half_div(double a, double b, double eps)
{
  double x, f, f1, f2, f3;
  int sign_f1, sign_f2, sign_f3;
  x = (a + b) / 2;
  f = func_orig(x);
  if (f == 0)
  {
    return x;
  }
  else
  {
    do
    {
      f1 = func_orig(x);
      f2 = func_orig(a);
      f3 = func_orig(b);
      sign_f1 = sign(f1);
      sign_f2 = sign(f2);
      sign_f3 = sign(f3);
      if (sign_f1 != sign_f3)
      {
        a = x;
        b = b;
        x = (a + b) / 2;
        f = func_orig(x);
      }
      else if (sign_f1 != sign_f2)
      {
        b = x;
        a = a;
        x = (a + b) / 2;
        f = func_orig(x);
      }
    } while (f != 0);
    return x;
  }

}

double newton(double eps)
{
  double f, df, x;
  x = 4;
  do
  {
    f = 3.0 * x - 4 * log(x) - 5;
    df = 3 - (4 / x);
    if (df != 0)
    {
      x = x - f / df;
    }
  } while (abs(f) > eps);
  return x;
}

double iter(double a, double b, double eps)
{
  double x0, x1;
  x0 = (a + b) / 2;

  do
  {
    x1 = function(x0);
    if (fabs(x1 - x0) < eps)
    {
      break;
    }
    else
    {
      x0 = x1;
    }
  }
  while ((abs(a - x0) > eps) and (fabs(b - x0) > eps));

  return x1;
}

int main()
{
  double value;
  value = iter(2, 4, 0.000001);
  cout << "Метод иттераций:" << "  " << value << endl;
  value = newton(0.000001);
  cout << "Метод Ньютона:" << "  " << value << endl;
  value = half_div(2, 4, 0.000001);
  cout << "Метод половинного деления:" << "  " << value << endl;
  return 0;
}
