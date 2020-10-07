#include <iostream>
using namespace std;

bool equalityCondition(int, int, int);

int main()
{
    int spmi[3]; //array to store info of sparse matrix
    for (int i = 0; i < 3; i++)
        cin >> spmi[i];
    int cm[spmi[2]][3]; //sparse matrix in triplet form
    for (int i = 0; i < spmi[2]; i++)
        for (int j = 0; j < 3; j++)
            cin >> cm[i][j];
    int ii[2]; //initial indices for starting traversal
    for (int i = 0; i < 2; i++)
        cin >> ii[i];
    int spm[spmi[0]][spmi[1]]; //sparse matrix
    int k = 0;
    for (int i = 0; i < spmi[0]; i++)
    {
        for (int j = 0; j < spmi[1]; j++)
        {
            if ((j == cm[k][1]) && (i == cm[k][0]))
            {
                spm[i][j] = cm[k][2];
                k++;
            }
            else
            {
                spm[i][j] = 0;
            }
        }
    }
    int outm[spmi[2]][4]; //output matrix
    k = 0;
    int l = 1;
    char dom='d'; //direction of movement
    int m = -1;
    int temp = 0;
    while(k<spmi[0]*spmi[1])
    {
        while(equalityCondition(temp, l, k))
        {
            if(spm[ii[0]][ii[1]]!=0)
            {    
                m++;
                outm[m][0] = ii[0];
                outm[m][1] = ii[1];
                outm[m][2] = spm[ii[0]][ii[1]];
                outm[m][3] = ((dom=='d') ? (1) : (3)); 
            }
            if((k==0 && temp!=l) || (k!=1 && temp!=l-1))
            {
                if(dom=='d')
                {
                    ii[0]++;
                }
                else if(dom=='u')
                {
                    ii[0]--;
                }
            }
            temp++;
            k++;
        }
        temp = 0;
        if(dom=='u')
        {    
            dom='l';
            ii[1]--;
        }
        else if(dom=='d')
        {    
            dom='r';
            ii[1]++;
        }
        if(k>=spmi[0]*spmi[1])    
            break;
        while(temp<l)
        {
            if(spm[ii[0]][ii[1]]!=0)
            {    
                m++;
                outm[m][0] = ii[0];
                outm[m][1] = ii[1];
                outm[m][2] = spm[ii[0]][ii[1]];
                outm[m][3] = ((dom=='r') ? (2) : (4)); 
            }
            if(temp!=l-1)
            {
                if(dom=='l')
                {
                    ii[1]--;
                }
                else if(dom=='r')
                {
                    ii[1]++;
                }
            }
            temp++;
            k++;
        }
        temp = 0;
        if(dom=='l')
        {    
            dom='d';
            ii[0]++;
        }
        else if(dom=='r')
        {    
            dom='u';
            ii[0]--;
        }
        l++;
    }
    for(int i=0; i<spmi[2]; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<outm[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool equalityCondition(int temp, int l, int k)
{
    if(k==0 || k==1)
        return temp<=l;
    else
        return temp<l;
}