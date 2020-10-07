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

class frequency{
    private:
    public:
    protected:
    void to_display(int x)
    {
        for(x=1;x<=100;x++)
        {
        cout<<x;
        }
    }
    void to_display1(int y)
    {
        for(y=1;y<=100;y++)
        {
        cout<<y;
        }
    }
    void to_display2(int z)
    {
        for(z=1;z<=100;z++)
        {
        cout<<z;
        }
    }
    void to_display3(int a)
    {
        for(a=1;a<=100;a++)
        {
        cout<<a;
        }
    }
    void to_display4(int b)
    {
        for(b=1;b<=100;b++)
        {
        cout<<b;
        }
    }
    void to_display5(int c)
    {
        for(c=1;c<=100;c++)
        {
        cout<<c;
        }
    }
    void to_display6(int d)
    {
        for(d=1;d<=100;d++)
        {
        cout<<d;
        }
    }
    void to_display7(int e)
    {
        for(e=1;e<=100;e++)
        {
        cout<<e;
        }
    }
    void to_display8(int f)
    {
        for(f=1;f<=100;f++)
        {
        cout<<f;
        }
    }
    void to_display9(int g)
    {
        for(g=1;g<=100;g++)
        {
        cout<<g;
        }
    }
    void to_display10(int h)
    {
        for(h=1;h<=100;h++)
        {
        cout<<h;
        }
    }
    void to_display11(int i)
    {
        for(i=1;i<=100;i++)
        {
        cout<<i;
        }
    }
    void to_display14(int l)
    {
        for(l=1;l<=100;l++)
        {
        cout<<l;
        }
    }
    void to_display12(int j)
    {
        for(j=1;j<=100;j++)
        {
        cout<<j;
        }
    }
    void to_display13(int k)
    {
        for(k=1;k<=100;k++)
        {
        cout<<k;
        }
    }
};

class frequency1{
    private:
    public:
    protected:
    void to_display(int x)
    {
        for(x=1;x<=100;x++)
        {
        cout<<x;
        }
    }
    void to_display1(int y)
    {
        for(y=1;y<=100;y++)
        {
        cout<<y;
        }
    }
    void to_display2(int z)
    {
        for(z=1;z<=100;z++)
        {
        cout<<z;
        }
    }
    void to_display3(int a)
    {
        for(a=1;a<=100;a++)
        {
        cout<<a;
        }
    }
    void to_display4(int b)
    {
        for(b=1;b<=100;b++)
        {
        cout<<b;
        }
    }
    void to_display5(int c)
    {
        for(c=1;c<=100;c++)
        {
        cout<<c;
        }
    }
};
class frequency2{
    private:
    public:
    protected:
};
class frequency3{
    private:
    public:
    protected:
};
class frequency4{
    private:
    public:
    protected:
};
class frequency5{
    private:
    public:
    protected:
};
class frequency6{
    private:
    public:
    protected:
};
class frequency7{
    private:
    public:
    protected:
};
class frequency8{
    private:
    public:
    protected:
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

