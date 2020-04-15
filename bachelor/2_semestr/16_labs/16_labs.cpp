//Духанин Алексей. 16 лаб.
#include <iostream>
using namespace std;
int * create_arr(int n)
{
    int *arr = new int[n];
    for(int counter = 0; counter < n; counter++)
    {
        arr[counter] = counter;
        cout << counter << '\t';
    }
    cout << endl;
    return arr;
}
int search_murrr(string words, string subwords)
{
    int words_len, subwords_len, pos;
    int arr[256];
    words_len = words.size();
    subwords_len = subwords.size();
    for(int counter = 0; counter < 256; counter++)
    {
        arr[counter] = subwords_len;
    }
    for(int counter = subwords_len - 2; counter >= 0; counter--)
    {
        if(arr[int((unsigned char)subwords[counter])] == subwords_len)
        {
            arr[int((unsigned char)subwords[counter])] = subwords_len - counter - 1;
        }
    }
    pos = subwords_len - 1;
    while(pos < words_len)
    {
        if(subwords[subwords_len - 1] != words[pos])
        {
            pos += arr[int((unsigned char)words[pos])];
        }
        else
        {
            for(int counter = subwords_len - 1; counter >= 0; counter--)
            {
                if(subwords[counter] != words[pos - subwords_len + counter + 1])
                {
                    pos += arr[int((unsigned char)words[pos - subwords_len + counter + 1])];
                    break;
                }
                else if (counter == 0)
                {
                    return pos - subwords_len + 1;
                }
            }
        }
    }
    return 2;
}

int search_inter(int * arr, int n, int num)
{
    int left, right, index;
    left = index = 0;
    right = n;
    while((left <= right))
    {
        index = left + ((num - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        if(arr[index] < num)
        { 
            left = index + 1;
        }
        else if (arr[index] > num)
        { 
            right = index + 1;
        }
        else
        {
            break;
        }
    }
    if (arr[left] == num)
    {
        return left;
    }
    else if (arr[right] == num)
    {
        return left;
    }
    return -2;
}

int main(int argc, char * argv[])
{
    int * arr;
    int n = 10;
    arr = create_arr(n);
    int index_boer_mur = search_murrr(argv[1], argv[2]);
    index_boer_mur  == 2 ? cout << "Not search" << endl : cout << "Боер - Мур: " << index_boer_mur << endl;
    int index_inter = search_inter(arr, n, atoi(argv[3]));
    index_inter == -2 ? cout << "Not search" << endl : cout << "Интерпол.: " << index_inter << endl;
    return 0;
}
