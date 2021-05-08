#include <iostream>
using namespace std;

int count_sdnf = 0;
int vec[8];
int xyz[8][4] = {
	{0, 0, 0, 0},
	{1, 0, 0, 1},
	{2, 0, 1, 0},
	{3, 0, 1, 1},
	{4, 1, 0, 0},
	{5, 1, 0, 1},
	{6, 1, 1, 0},
	{7, 1, 1, 1},
};
//Функция ввода вектора
void input_vec()
{
	cout << "Введите вектор функции" << endl;
	for(int i = 0; i < 8; i++)
	{
		cin >> vec[i]; //Введение вектора пользователем
		!vec[i] ? vec[i] = 0 : vec[i] = 1; //Замена всех чисел на 1, кроме 0
	}
	for (int i = 0; i < 8; i++)
	{
		cout << "====";
	}
	//Вывод таблицы истинности
	cout << endl << "№\t" << "X\t" << "Y\t" << "Z\t" << "F\t" << endl;
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout << xyz[i][j] << "\t";
		}
		cout << vec[i] << endl;
	}
}
//Функция вывода СДНФ
void out_sdnf()
{
	//Подсчёт количества СДНФ
	for(int i = 0; i < 8; i ++)
	{
		if(vec[i])
		{
			count_sdnf++;
		}
	}
	if(!count_sdnf)
	{
		cout << "Данная функция не имеет СДНФ" << endl; //Если количество элементов равно 0, то сднф нет
	}
	else
	{
		cout << "Количество элементов СДНФ - " << count_sdnf << endl;
		//Вывод СДНФ
		for(int i = 0; i < 8; i++)
		{
			if(vec[i])
			{
				if(xyz[i][1])
				{
					cout << "x";
				}
				else
				{
					cout << "-x";
				}
				if(xyz[i][2])
				{
					cout << "y";
				}
				else
				{
					cout << "-y";
				}
				if(xyz[i][3])
				{
					cout << "z";
				}
				else
				{
					cout << "-z";
				}
				cout << "\t||";
			}
		}
		cout << endl;
	}
}
//Функция минимизации методом Квайна
void min_Kvain()
{
	if(count_sdnf == 8)
	{
		cout << "После минимизации будет 1" << endl;
	}
	else
	{

	}
}

int main()
{
	input_vec();   //Вызов функции ввода вектора
	out_sdnf();    //Вызов Функции вывода СДНФ
	if(count_sdnf != 0)
	{
		min_Kvain(); //Вызов функции минимизации методом Квайна
	}
}
