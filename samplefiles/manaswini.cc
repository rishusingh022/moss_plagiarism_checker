#include<iostream>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    int k=0,n;
    string str;
    cin>>str;
    cin>>n;
    int x[100];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    int b[1000];
    char a[1000];
    for(int i=0;str[i]!='\0';i++)
    { int c=0;
        for(int j=0;j<k;j++)
        {
            if(a[j]==str[i])
            {
                b[j]++;
                c=1; break;
            }
        }
        if(c==0)
        {
            a[k]=str[i];
            b[k]=1;
            k++;
        }
    }
    for(int i=0;i<k;i++)
    {
        cout<<a[i]<<" "<<b[i]<<" ";
    }
    for(int j=0;j<n;j++)
    {
        for(int m=0;m<k;m++)
        {
            if(b[m]==x[j])
            { int z=0;
                for(int l=m+1;l<k;l++)
                {
                    if(b[l]==x[j])
                    {
                        z=l;break;
                    }
                    
                }
                if(z!=0){
                for(int p=m+1;p<z;p++)
                    {
                        if (b[p]<x[j])
                        {
                            char temp1;
                            int temp2;
                            temp1 = a[p];
                            temp2=b[p];
                            for(int h=p-1;h>=0;h--)
                            {
                                a[h+1]=a[h];
                                b[h+1]=b[h];
                            }
                            a[0]=temp1;;
                            b[0]=temp2;
                        }
                        else if(b[p]>x[j])
                        {
                            
                            a[k]=a[p];
                            b[k]=b[p];
                            for(int h=p;h<=k;h++)
                            {
                                a[h]=a[h+1];
                                b[h]=b[h+1];
                                
                            }
                            p--;
                            z--;
                        }
                    }
                }
                    
            }
        }
        cout<<endl;
        for(int h=0;h<k;h++)
        {
            cout<<a[h]<<" "<<b[h]<<" ";
        }
    }
}