#include <iostream>
#include <unistd.h>
using namespace std;

#define x 0
#define y 1

int board [8][8];
int fersi [8][2];

int locale_fer(int f)
{
  if (f < 8)
  {
    //зполнение единцами клеток под ударом
    for (int external = 0; external < 8; external++) // y
    {
      for (int inner = 0; inner < 8; inner++) //x
      {
        if (fersi[f][x] == inner)
        {
          board[external][inner] = 1;
        }
        if (fersi[f][y] == external)
        {
          board[external][inner] = 1;
        }
        if (external == (1 * (inner - fersi[f][x]) + fersi[f][y]))
        {
          board[external][inner] = 1;
        }
        if (external == (-1 * (inner - fersi[f][x]) + fersi[f][y]))
        {
          board[external][inner] = 1;
        }
        //cout << board[external][inner] << " ";
      }
      //cout << endl;
    }
    for (int external = 0; external < 8; external++)
    {
      for (int inner = 0; inner < 8; inner++)
      {
        if (board[external][inner] == 0)
        {
          fersi[f + 1][x] = inner;
          fersi[f + 1][y] = external;

          locale_fer(f + 1);
        }

      }
    }
  }
  else
  {
    return 0;
  }
  return 0;
}

void board_print()
{
  for (int external = 0; external < 8; external++)
  {
    for (int inner = 0; inner < 8; inner++)
    {
      for (int counter = 0; counter < 8; counter++)
      {
        if ((fersi[counter][x] == inner) and (fersi[counter][y] == external))
        {
          cout << " F";
        }
      }
      cout << " .";
    }
    cout << endl;
  }
}

int main()
{
  srand(time(NULL));
  printf("\033[H\033[2J\033[3J");

  fersi[0][x] = 0;
  fersi[0][y] = 5;

  locale_fer(0);
  for (int external = 0; external < 8; external++)
  {
    for (int inner = 0; inner < 2; inner++)
    {
      cout << fersi[external][inner] << " ";
    }
    cout << endl;
  }
  board_print();
  return 0;
}
