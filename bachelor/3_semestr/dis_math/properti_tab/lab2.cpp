#include <iostream>

using namespace std;

int arr[100][100];
int n_arr = 0;

bool refl     = true;
bool antirefl = true;
bool simm     = true;
bool antisimm = true;
bool asimm    = true;
bool conn     = true;
bool tran     = true;

//Функция определения рефлексивности
void reflex_fun()
{
	for(int i = 0; (i < n_arr) and (refl); i++)
	{
		if(!arr[i][i])
		{
			refl = false;
		}
	}
}

//Функция определения антирефлексивности
void antireflex_fun()
{
	for(int i = 0; (i < n_arr) and (antirefl); i++)
	{
		if(arr[i][i])
		{
			antirefl = false;
		}
	}
}

//Функция определения симметричности
void simm_fun()
{
	for(int i = 0; (i < n_arr) and (simm); i++)
	{
		for(int j = 0; (j < n_arr) and (simm); j++)
		{
			if(i != j)
			{
				if(arr[i][j] != arr[j][i])
				{
					simm = false;
				}
			}
		}
	}
}

//Функция определения антисимметричности
void antisimm_fun()
{
		for(int i = 0; (i < n_arr) and (antisimm); i++)
		{
			for(int j = 0; (j < n_arr) and antisimm; j++)
			{
				if(i != j)
				{
					if(arr[i][j] == arr[j][i])
					{
						antisimm = false;
					}
				}
			}
		}
}

//Функция определения ассиметричности
void asimm_fun()
{
	if(!antirefl)
	{
		asimm = false;
	}
	for(int i = 0; (i < n_arr) and (asimm); i++)
	{
		for(int j = 0; (j < n_arr) and (asimm); j++)
		{
			if((i != j) and (arr[i][j]) and (!arr[j][i]))
			{
				asimm = false;
			}
		}
	}
}

//Функция определения связности
void conn_fun()
{
	for(int i = 0; (i < n_arr) and (conn); i++)
	{
		for(int j = 0; (j < n_arr) and (conn); j++)
		{
			if((i != j) and (!arr[i][j]) and (!arr[j][i]))
			{
				conn = false;
			}
		}
	}
}

//Функция определения транзитивности
void tran_fun()
{
	for(int i = 0; (i < n_arr) and (tran); i++)
	{
		for(int j = 0; (j < n_arr) and (tran); j++)
		{
			if(arr[i][j])
			{
				for(int k = j; (k < n_arr) and (tran); k++)
				{
					if((arr[j][k]) and !(arr[i][k]))
					{
						tran = false;
					}
				}
			}
		}
	}
}

//Функция ввода таблицы
void input_arr()
{
	cout << "Введите размерность таблицы" << endl;
	cin >> n_arr; //ввод размерности
	cout << "Введите значения таблицы" << endl; //ввод таблицы
	for(int i = 0; i < n_arr; i++)
	{
		for(int j = 0; j < n_arr; j++)
		{
			cout << "Элемент" << i << " " << j << " ";
			cin >> arr[i][j];
		}
		cout << endl;
	}

	//Заменяются все элементы на 1(кроме 0)
    for (int i = 0; i < n_arr; i++)
    {
        for (int j = 0; j < n_arr; j++)
        {
            if (arr[i][j] != 0)
            {
                arr[i][j] = 1;
            }
        }
        cout << endl;
    }
    //Вывод таблицы
    cout << "Вы ввели:" << endl;
    for(int i = 0; i < n_arr; i++)
    {
    	for(int j = 0; j < n_arr; j++)
    	{
    		cout << arr[i][j] << "\t";
			}
			cout << endl;
    }
}

//Функция вывода свойств
void properties()
{
	reflex_fun();      //Вызов функции определения рефлексивности
	antireflex_fun(); //Вызов функции определения антирефлексивности
	simm_fun();      //Вызов функции определения симметричности
	antisimm_fun(); //Вызов функции определения антисимметричности
	asimm_fun();   //Вызов функции определения ассиметричности
	conn_fun();   //Вызов функции определения связности
	tran_fun();  //Вызов функции определения транзитивности

	if(refl)
	{
		cout << "Таблица обладает рефлексивностью"     << endl;
	}
	if(antirefl)
	{
		cout << "Таблица обладает антирефлексивностью" << endl;
	}
	if(simm)
	{
		cout << "Таблица обладает симметричностью"     << endl;
	}
	if(antisimm)
	{
		cout << "Таблица обладает антисимметричностью" << endl;
	}
	if(asimm)
	{
		cout << "Таблица обладает ассиметричностью"    << endl;
	}
	if(conn)
	{
		cout << "Таблица обладает связностью"          << endl;
	}
	if(tran)
	{
		cout << "Таблица обладает транзитивностью"     << endl;
	}
	if(!refl)
	{
		cout << "Таблица не обладает рефлексивностью"     << endl;
	}
	if(!antirefl)
	{
		cout << "Таблица не обладает антирефлексивностью" << endl;
	}
	if(!simm)
	{
		cout << "Таблица не обладает симметричностью"     << endl;
	}
	if(!antisimm)
	{
		cout << "Таблица не обладает антисимметричностью" << endl;
	}
	if(!asimm)
	{
		cout << "Таблица не обладает ассиметричностью"    << endl;
	}
	if(!conn)
	{
		cout << "Таблица не обладает связностью"          << endl;
	}
	if(!tran)
	{
		cout << "Таблица не обладает транзитивностью"     << endl;
	}
}

int main()
{
	input_arr(); //Вызов функции ввода таблицы
	properties();//Вызов функции вывода свойств таблицы
}
