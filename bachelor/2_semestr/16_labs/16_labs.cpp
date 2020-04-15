//Духанин Алексей. 16 лаб.
#include <iostream>
using namespace std;

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

int main(int argc, char * argv[])
{
    int index_boer_mur = search_murrr(argv[1], argv[2]);
    index_boer_mur  == 2 ? cout << "Not search" << endl : cout << "Боер - Мур: " << index_boer_mur << endl;
    
    return 0;
}
