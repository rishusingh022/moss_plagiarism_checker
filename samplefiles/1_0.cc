#include <iostream>
#include <string.h>
using namespace std;

class CharFreq
{
public:
    char ch;
    int freq;
    CharFreq()
    {
        freq = 0;
    }
};

int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    int frequencies[n];
    for (int i = 0; i < n; i++)
        cin >> frequencies[i]; 
    CharFreq cf[26]; //frequency array
    int lofa = -1;   //length of frequency array
    int flag;
    for (int i = 0; i < str.length(); i++)
    {
        flag = 0;
        for (int k = 0; k <= lofa; k++)
        {
            if (str[i] == cf[k].ch)
                flag = 1;
        }
        if (flag == 1)
            continue;
        else
        {
            lofa++;
            cf[lofa].ch = str[i];
            cf[lofa].freq = 1;
            for (int j = i + 1; j < str.length(); j++)
            {
                if (str[i] == str[j])
                    cf[lofa].freq++;
            }
        }
    }
    for (int i = 0; i <= lofa; i++)
    {
        cout << cf[i].ch << " " << cf[i].freq << " ";
    }
    cout << endl;
    CharFreq temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < lofa; j++)//decide where to put flag =0
        {
            if (cf[j].freq == frequencies[i])
            {   
                flag = 0;
                int k = j + 1;
                while (k <= lofa)
                {
                    if (cf[k].freq == frequencies[i])
                    {
                        flag = 1;
                        break;
                    }
                    k++;
                }
                if (flag == 1)
                {
                    for (int l = j + 1; l < k; l++)
                    {
                        if (cf[l].freq > frequencies[i])
                        {
                            temp = cf[l];
                            for (int m = l; m < lofa; m++)
                                cf[m] = cf[m+1];
                            cf[lofa] = temp;
                            l--;
                            k--;
                        }
                        else if(cf[l].freq < frequencies[i])
                        {
                            temp = cf[l];
                            for (int m = l; m >0; m--)
                                cf[m] = cf[m-1];
                            cf[0] = temp;
                        }
                    }
                }
            }
        }
        for (int j = 0; j <= lofa; j++)
        {
            cout << cf[j].ch << " " << cf[j].freq << " ";
        }
        cout << endl;
    }
}
