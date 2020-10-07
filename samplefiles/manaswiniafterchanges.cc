#include<iostream>
#include<stdio.h>
using namespace std;
void display(char a[],int b[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" "<<b[i]<<" ";
    }
}
int main()
{
    int k=0,n,i,j,m,l,z;
    int b[1000];
    char a[1000];
    cin>>a;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    
    for(int i=0;a[i]!='\0';i++)
    { int c=0;
        for(int j=0;j<k;j++)
        {
            if(a[j]==a[i])
            {
                b[j]++;
                c=1; break;
            }
        }
        if(c==0)
        {
            a[k]=a[i];
            b[k]=1;
            k++;
        }
    }
   display(a,b,k);
    for(j=0;j<n;j++)
    {
        for( m=0;m<k;m++)
        {
            if(b[m]==x[j])
            { z=0;
                for(l=m+1;l<k;l++)
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
                            char ch;
                            int t;
                            ch = a[p];
                            t=b[p];
                            for(int h=p-1;h>=0;h--)
                            {
                                a[h+1]=a[h];
                                b[h+1]=b[h];
                            }
                            a[0]=ch;;
                            b[0]=t;
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
        display(a,b,k);
    }
}