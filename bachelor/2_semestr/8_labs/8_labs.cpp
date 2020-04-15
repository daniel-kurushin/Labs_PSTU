//Духанин Алексей, лаб. 8
/*
    14. Структура "Стадион":
    • название;
    • адрес;
    • вместимость;
    • виды спорта.
Удалить элемент с заданным названием, добавить 2 элемента после элемента с указанным номером.
*/

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

struct stadion
{
    string name;
    string locale;
    int humans;
    string sports;
};

int main(int argc, char *argv[])
{
    
    FILE *f;
    stadion data;
    int n;
    f = fopen("stadion", "wb");
    n = atoi(argv[1]);
    for(int counter = 0; counter < n; counter++)
    {
        cout << counter << endl;
        cout << "How name?" ;
        cin.ignore(32767, '\n');
        getline(cin, data.name);
        cout << "How locale?" ;
        cin.ignore(32767, '\n');
        getline(cin, data.locale);
        cout << "How humans?";
        cin >> data.humans;
        cout << "How sports?" ;
        cin.ignore(32767, '\n');
        getline(cin, data.sports);
        fwrite(&data, sizeof(stadion), 8, f);
    }
    fclose(f);
    ifstream file ("stadion");   
    string s;  
    for(file >> s; !file.eof(); file >> s) 
                 cout << s << endl;
    return 0;
}
