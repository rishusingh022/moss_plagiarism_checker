#include <iostream>
using namespace std;
class stack
{
    private:
         int top;
         int max;
        int arr[100];
    public:
        stack( int n)
        {
            max = n;
            top=-1;
        }
        void push(int value)
        {
            if(top==max-1)
            {
                cout<<"stack full";
                return;
            }
            top=top+1;
            arr[top]=value;
        }
        int peek()
        {
            return arr[top];
        }
        int pop()
        {
            if(top==-1)
            {
                cout<<"empty";
                return 0;
            }
            int value=arr[top];
            top--;
            return value;
        }
        void display()
        {
            while(top!=-1)
            {
                cout<<arr[top];
                top--;
            }
        }
};
int main()
{
    stack s(100);
    int column[1000],row[1000],value[1000],i,j,k,n,r,c,a[1000][1000],flag=0,r1,c1,x,count=1,direction[999];
    cin>>r>>c>>n;
    for(i=0;i<n;i++)//to get input of sparse matrix
    {
        cin>>row[i];
        cin>>column[i];
        cin>>value[i];
    }
    //to convert sparse input to normal matrix form
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    {
        flag=0;
        for(k=0;k<n;k++)
            if(i==row[k] && j==column[k])
            {
                a[i][j]=value[k];
                flag=1;
            }
        if(flag==0)
        {
            a[i][j]=0;
        }
    }
    direction[99]={0};
    //to print the matrix in normal form
    /*for(i=0;i<r;i++){
    for(j=0;j<c;j++)
    cout<<a[i][j]<<" ";
    cout<<endl;
    }
    */
    cin>>r1>>c1;
    
    x=a[r1][c1];
    if(x!=0)
    {
        for(k=0;k<n;k++)
        {
            if(value[k]==a[r1][c1])
             {
                direction[k]=1;
                cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<direction[k]<<endl;
            }                        
        }
    }
        while(count<r)
        {
            if(count%2!=0)//odd count implies go down and right by same count
            {
                for(i=0;i<count;i++)//to go down by certain no. of elements 
                {
                    x=a[++r1][c1];
                    if(a[r1][c1]!=0)//down
                    {
                        for(k=0;k<n;k++)
                        {
                            if(value[k]==a[r1][c1])
                                {
                                    direction[k]=1;
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<direction[k]<<endl;
                                }
                        }
                    }
                    
                    else 
                    
                    {
                        continue;
                    }
                }
                
                for(i=0;i<count;i++)//to go right by certain no. of elements 
                {
                    x=a[r1][++c1];
                    if(a[r1][c1]!=0)//right
                    {
                        for(k=0;k<n;k++)
                        {
                            if(value[k]==a[r1][c1])
                               {
                                    direction[k]=2;
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<direction[k]<<endl;
                                }
                        }
                    }
                    
                    else 
                    {
                        continue;
                    }
                }
                count++;
            }
            else
            {
                for(i=0;i<count;i++)//to go up by certain no. of elements 
                {
                    x=a[--r1][c1];
                    if( a[r1][c1]!=0)//up
                    {
                        for(k=0;k<n;k++)
                        {
                            if(value[k]==a[r1][c1])
                                {
                                    direction[k]=3;
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<direction[k]<<endl;
                                }
                        }
                    }
                    else 
                    {
                        continue;
                    }
                }
                
                for(i=0;i<count;i++)//to go left by certain no. of elements 
                {
                    x=a[r1][--c1];
                    if(a[r1][c1]!=0)//left
                    {
                        for(k=0;k<n;k++)
                        {
                            if(value[k]==a[r1][c1])
                               {
                                    direction[k]=4;
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<direction[k]<<endl;
                                }
                        }
                    }
                    
                    else 
                    {
                        continue;
                    }
                }
                count++;
            }
        }
        if(count==r)
        {
            if(count%2!=0)//odd count implies go down and right by same count
            {
                for(i=0;i<count- 1;i++)//to go down by certain no. of elements 
                {
                    x=a[++r1][c1];
                    if(a[r1][c1]!=0)//down
                    {
                        for(k=0;k<n;k++)
                        {
                            if(value[k]==a[r1][c1])
                                {
                                    direction[k]=1;
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<direction[k]<<endl;
                                }
                        }
                    }
                    
                    else 
                    
                    {
                        continue;
                    }
                }
                count++;
            }
            else
            {
                for(i=0;i<count- 1;i++)//to go up by certain no. of elements 
                {
                    x=a[--r1][c1];
                    if( a[r1][c1]!=0)//up
                    {
                        for(k=0;k<n;k++)
                        {
                            if(value[k]==a[r1][c1])
                                {
                                    direction[k]=3;
                                    cout<<row[k]<<" "<<column[k]<<" "<<value[k]<<" "<<direction[k]<<endl;
                                }
                        }
                    }
                    else 
                    {
                        continue;
                    }
                }
                count++;
            }
        }
    int b[500];
    for(i=0;i<n;i++)
    b[i]=column[i];
    for(i=0;i<n;i++)
	{int c=i+1;
	for(j=c ;j<n;j++)
	{
		if(b[i]==b[j])
		{
			for(k=j;k<n;k++)
			{
				b[k]=b[k+1];
			}
			n=n-1;
			i=i-1;
		}
	}
	}
    return 0;
}
