#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};
node *start=NULL;
void insert1(int n)
{
    node  *temp=start;
    node *ptr=new node;
    ptr->value=n;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
        return;
    }
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    temp->next=ptr;
}
void insert2(int x, int y)
{
    node *temp=start;
    int count=0,pos;
    while(temp!=NULL)
    {
        count++;
        if(temp->value==y)
        {
            node *ptr=new node;
            ptr->value=x;
            ptr->next=temp->next;
            temp->next=ptr;
            return;
        }
        else if(temp->value==x)
        {
            pos=count;
            break;
        }
        else temp=temp->next;
    }
    count=1;
    temp=start;
    while(temp!=NULL || count!=pos-1)
    {
        temp=temp->next;
        count++;
        
    }
    node *ptr=new node;
    ptr->value=y;
    ptr->next=temp->next;
    temp->next=ptr;
    
}
void insert3(int x, int y, int z)
{
    node *temp=start;
    node *ptr=new node;
    ptr->value=x;
    ptr->next=NULL;
    while(temp->next!=NULL)
    {
        if(temp->value==z && (temp->next)->value==y)
        {
            ptr->next=temp->next;
            temp->next=ptr;
        }
    }
}

int main()
{
    node s;
    insert1(1);
    long long int column[500],row[500];
    long long int value[500],a[500][500];
    int count=1;
    long long int i,j,k,n,r;
    long long int c,r1,c1,x;
    cin>>r;
    cin>>c;
    cin>>n;
    i=0;
    while(i<n)
    {
        cin>>row[i]>>column[i]>>value[i];
        i++;
    }

    i=0;
    while(i<r)
    {
    j=0;
    while(j<c)
    {
        k=0;
        while(k<n)
        {
            if(i!=row[k] || j!=column[k])
            {
                a[i][j]=0;
                k++;
                continue;
            }
            else if(i==row[k] && j==column[k])
            {
                a[i][j]=value[k];
                break;
            }
            else {
            k++;
            continue;}
        }
        j++;
    }
        i++;
    }
    
    int o=10;
    int p,q;
    p=4;
    q=12;
    o=p+q;
    p=p-q;
    q=p-o;
    o=p+ 16;
    p=p+ 34;
    q= p- 3;
    q=q-p;
    o=o+p-q;
    
    cin>>r1;
    cin>>c1;
    x=a[r1][c1];
    if(x==0)
    {
        x=0;
    }
    else
    {
        k=0;
        while(k<n)
        {
            if(value[k]==x)
             {
                cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<1<<endl;
            } 
            k++;
        }
    }
    count=1;
    for(count=1;count<r;count=count+ 1)
        
        {
            if(count % 2 == 0)
            {
                i=0;
                while(i<count)

                {
                    x=a[--r1][c1];
                    if( a[r1][c1]==0)//up
                    {
                        i=i+ 1;
                        continue;
                    }
                    else 
                    {
                        k=0;
                        while(k<n)
                        {
                            if(value[k]==a[r1][c1])
                                {
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<3<<endl;
                                }
                            k++;
                        }
                    }
                    i=i+1;
                }
                
                i=0;
                while(i<count)
                {
                    x=a[r1][--c1];
                    if(a[r1][c1]==0)//left
                    {
                        i=i+ 1;
                        continue;
                    }
                    
                    else 
                    {
                        k=0;
                        while(k<n)
                        {
                            if(value[k]==a[r1][c1])
                                {
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<4<<endl;
                                }
                            k++;
                        }
                    }
                    i=i+ 1;
                }
            }
            else 
            {
                i=0;
                while(i<count) 
                {
                    x=a[++r1][c1];
                    if(a[r1][c1]==0)//down
                    {
                        i=i+ 1;
                        continue;
                    }
                    
                    else 
                    
                    {
                       k=0;
                        while(k<n)
                        {
                            if(value[k]==a[r1][c1])
                                {
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<1<<endl;
                                }
                            k++;
                        }
                    }
                    i=i+ 1;
                }
                
                i=0;
                while(i<count)
                {
                    x=a[r1][++c1];
                    if(a[r1][c1]==0)//right
                    {
                        i=i+ 1;
                        continue;
                    }
                    
                    else 
                    {
                       k=0;
                        while(k<n)
                        {
                            if(value[k]==a[r1][c1])
                               {
                                   cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<2<<endl;
                                }
                            k++;
                        }
                    }
                    i=i+ 1;
                }
            }
        }
        if(count==r)
        {
            if(count%2==0)
            {
                i=0;
                while(i<count- 1) 
                {
                    x=a[--r1][c1];
                    if( a[r1][c1]==0)//up
                    {
                        i=i+ 1;
                        continue;
                    }
                    else 
                    {
                        k=0;
                        while(k<n)
                        {
                            if(value[k]==a[r1][c1])
                                {
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<3<<endl;
                                }
                            k++;
                        }
                    }
                    i=i+ 1;
                }
            }
            else
            {
                i=0;
                while(i<count- 1)
                {
                    x=a[++r1][c1];
                    if(a[r1][c1]==0)//down
                    {
                        i=i+ 1;
                        continue;
                    }
                    
                    else 
                    
                    {
                        k=0;
                        while(k<n)
                        {
                            if(value[k]==a[r1][c1])
                                {
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<1<<endl;
                                }
                            k++;
                        }
                    }
                    i=i+ 1;
                }
            }
        }
    
    return 0;
}