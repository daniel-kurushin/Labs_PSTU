//Духанин Алексей, 13 лаб.
#include <iostream>
using namespace std;

unsigned long int eshechka(unsigned long int k)
{
 return k < 2 ? 1 : k * eshechka(k - 1);
}

int main(int argc, char* argv[])
{
  unsigned long int accuracy;
  long double e = 0.0;
  e = 1.0;
  accuracy = atoi(argv[1]);
  
  for(unsigned long int counter = 1; counter < accuracy; counter++)
  {
   e +=  1.0 / eshechka(counter);
  }
  cout << e << endl;
	return 0;
}
