#include <iostream>
#include <fstream>
using namespace std;

class TSP
{
    private:
    int arr[5][5], arr_work[5][5], arr_zero[5][5];
    int arr_min_x[5], arr_min_y[5], arr_end[6];
    int max_zero_x = 0;
    int max_zero_y = 0;
    int num_road = 0;
    public:
    TSP()
    {
        ifstream file_roads("roads.txt");
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                file_roads >> arr[i][j];
            }
        }
        file_roads.close();
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                arr_work[i][j] = arr[i][j];
                arr_zero [i][j] = -24;
            }
            arr_min_x[i] = arr_min_y[i] = arr_end[i] = 0;
        }
    } 
    void print()
    {
        cout << "Матрица смежности: " << endl;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cout << arr[i][j] << '\t';
            }
            cout << endl;
        }
    }
    void min_x()
    {
        cout << "Минимумы по х: ";
        int min = 0;
        for(int i = 0; i < 5; i++)
        {
            min = 100;
            for(int j = 0; j < 5; j++)
            {
                if(arr_work[i][j] >= 0)
                {
                    if(arr_work[i][j] < min)
                    {
                        min = arr_work[i][j];
                    }
                }
            }
            arr_min_x[i] = min;
        }
        for(int i = 0; i < 5; i++)
        {
            cout << arr_min_x[i] << '\t';
        }
        cout << endl;
    }
    void minus_x()
    {
        cout << "Вычетание минимумов х";
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j< 5; j++)
            {
                if(arr_work[i][j] >= 0)
                {
                    arr_work[i][j] -= arr_min_x[i];
                }
            }
        }
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cout << arr_work[i][j] << '\t';
            }
            cout << endl;
        }
    }
    void min_y()
    {
        cout << "Минимумы по у:";
        int min = 0;
        for(int i = 0; i < 5; i++)
        {
            min = 100;
            for(int j = 0; j < 5; j++)
            {
                if(arr_work[j][i] >= 0)
                {
                    if(arr_work[j][i] < min)
                    {
                        min = arr_work[j][i];
                    }
                }
            }
            arr_min_y[i] = min;
        }
        for(int i = 0; i < 5; i++)
        {
            cout << arr_min_y[i] << '\t';
        }
        cout << endl;
    }
    void minus_y()
    {
        cout << "Вычетание минимумов у: " << endl;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j< 5; j++)
            {
                if(arr_work[j][i] >= 0)
                {
                    arr_work[j][i] -= arr_min_y[i];
                }
            }
        }
        
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cout << arr_work[i][j] << '\t';
            }
            cout << endl;
        }
        cout << endl;
    }
    int min_x_in_line(int x_line, int x_zero)
    {
        int min = 100;
        for(int i = 0; i < 5; i++)
        {
            if((i != x_zero) and (arr_work[x_line][i] >= 0))
            {
                if(arr_work[x_line][i] < min)
                {
                    min = arr_work[x_line][i];
                }
            }
            if(arr_work[i][x_line] == -6)
            {
                min = 0;
            }
        }
        return min;
    }
    int min_y_in_line(int y_line, int y_zero)
    {
        int min = 100;
        for(int i = 0; i < 5; i++)
        {
            if((i != y_zero) and (arr_work[i][y_line] >= 0))
            {
                if(arr_work[i][y_line] < min)
                {
                    min = arr_work[i][y_line];
                }
            }
            if(arr_work[i][y_line] == -6)
            {
                min = 0;
            }
        }
        return min; 
    }
    void make_arr_zero()
    {
        int y, x;
        for(int  i = 0; i < 5; i++)
        {
            for(int  j = 0; j < 5; j++)
            {
                if(arr_work[i][j] == 0)
                {
                    x = min_x_in_line(i, j);
                    y = min_y_in_line(j, i);
                    arr_zero[i][j] = x + y;
                }
            }
        }
    }
    void subtraction_line(int in_x, int in_y)
    {
        cout << num_road << endl;
        if((in_x >= 0) and (in_y >= 0))
        {
            for(int i = 0; i < 5; i++)
            {
            arr_work[in_x][i] = -6;
            arr_work[i][in_y] = -6;
            arr_zero[in_x][i] = -24;
            arr_zero[i][in_y] = -24;
            }
            arr_work[in_x][in_y] = -9;
            num_road++;
        }
    }
    void get_max_zero()
    {
        int max = -1;
        int c = 0;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if((arr_zero[i][j] >= 0) and (max < arr_zero[i][j]))
                {
                    max = arr_zero[i][j];
                    max_zero_x = i;
                    max_zero_y = j;
                }
                if(arr_zero[i][j] == -24)
                {
                    c++;
                }
            }
        }
    }
    void print_roads()
    {
        int counter = 0;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(arr_work[i][j] == -9)
                {
                    arr_end[counter] = i;
                    counter ++;
                    arr_end[counter] = j;
                }
            }
        }
        cout << "Готовый путь: " << endl;
        for(int i = 0; i < 6; i++)
        {
            cout << arr_end[i] + 1 << "  ";
            if(i != 5)
            {
                cout << " -> " << "  ";
            }
        }
        cout << endl;
    }
    int launch_tsp()
    {
        min_x();
        minus_x();
        
        min_y();
        minus_y();
        
        make_arr_zero();
        
        get_max_zero();
        subtraction_line(max_zero_x, max_zero_y);
        
        
        get_max_zero();
        subtraction_line(max_zero_x, max_zero_y);
        
        
        get_max_zero();
        subtraction_line(max_zero_x, max_zero_y);
        
        
        get_max_zero();
        subtraction_line(max_zero_x, max_zero_y);
        
        
        min_y();
        minus_y();
        
        make_arr_zero();
        get_max_zero();
        subtraction_line(max_zero_x, max_zero_y);
        print_roads();
        return 0;
        
    }
};

int main(int argc, char* argv[])
{
    TSP lab_32;
    
    lab_32.print();
    cout << endl;
    lab_32.launch_tsp();
    cout << endl;
    return 0;
}
