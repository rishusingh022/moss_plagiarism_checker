
#include <iostream>
using namespace std;
long long int multi_point_nodes[10000],circular=0;
long long int frequency[10000],counter=0;
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
struct node
{
      long long int value;
     long long  int freq=0;
    node *next;
};
void newer(  long long int x,  long long int f)//to add the new node frequency t the arry
{
    multi_point_nodes[counter]=x;
    frequency[counter]=f;
    counter++;
}
void update(  long long int x,  long long int f)//to update the frequency of node value
{
    for(  long long int i=0;i<counter;i++)
    {
        if(x==multi_point_nodes[i]){
        frequency[i]=f;
        }
    }
}
node *start=NULL;
void insert1(  long long int n)//for insert0
{
    node  *temp=start;
    node *ptr=new node();
    ptr->value=n;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
        newer(ptr->value,ptr->freq);
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    ptr->freq++;
    temp->next=ptr;
    newer(ptr->value,ptr->freq);
}
void insert2(  long long int x,   long long int y)//for insert1
{
    node *temp=start;
      long long int count=0,pos;
     
    while(temp!=NULL)
    {
        count++;
        if(temp->value==y)
        {
            
            node *ptr=new node();
            ptr->value=x;
            ptr->freq++;
            ptr->next=temp->next;
            temp->next=ptr;
            newer(ptr->value,ptr->freq);
            return ;
        }
        else if(temp->value==x)
        {
           
            pos=count;
            break;
        }
        else temp=temp->next;
    }
    count=1;
    node *nodietemp=start;
    if(start->value==x)
    {
        node *ptr=new node();
            ptr->value=y;
        start->freq=start->freq+ 1;
        update(start->value,start->freq);
        ptr->next=start;
        start=ptr;
        ptr->freq=0;
        newer(ptr->value,ptr->freq);
        return ;
    }
    while(count!=pos-1 && nodietemp!=NULL)
    {
    
        nodietemp=nodietemp->next;
        count++;
        
    }
    node *ptr=new node();
    ptr->value=y;
    ptr->freq=ptr->freq+1;
    newer(ptr->value,ptr->freq);
    ptr->next=nodietemp->next;
    nodietemp->next=ptr;
    
}
void insert3(  long long int x,   long long int y,  long long  int z)//for insert2
{
    node *ptr=new node();
    node *temp=start;
    ptr->value=x;
    ptr->freq++;
    newer(ptr->value,ptr->freq);
    ptr->next=NULL;
      long long int count=-1;
    while(temp!=NULL)
    {
        if(temp->value==z )
        {
            break;
        }
        else temp=temp->next;
    }
    node *first=temp;
    while(temp!=NULL)
    {
        count++;
        if(temp->value==y)
        {
            break;
        }
        else temp=temp->next;
    }
    node *end=temp;
    if(count%2!=0)
    count=(count)/2;
    else count=count/2 + 1;
    temp=first;
    long long int pos=0;
    while(pos!=count)
    {
        temp=temp->next;
        pos++;
    }
    ptr->next=temp->next;
    temp->next=ptr;
}

void linker(  long long int x,  long long  int p){//for linking 
    node *temp= start;
      long long int count=0;
    while(temp!=NULL || (temp)->value==start->value)//to know wich element has to be linked (first element)
    {
        if(temp->value==x)
            break;
        else temp=temp->next;
    }
    node *first_element=temp;
    while(count!=p)
    {
        if(temp->next==NULL)//normal to circular conversion
        {
            temp->next=start;
            circular=1;
            start->freq = start->freq + 1;
            update(start->value,start->freq);
        }
        temp=temp->next;
        count++;
    }
    
    {
        
        node *end=temp;
        
        end->freq=end->freq+ 1;
        update(end->value,end->freq);
        (first_element->next)->freq=(first_element->next)->freq - 1;
        update((first_element->next)->value,(first_element->next)->freq);
        
        
        first_element->next=end;
    }
}
void display()//to display the link list elements
{
    node *temp=start;
      long long int flag=0;
    if(start==NULL)//if link list empty
    {
    
    return;
    }
    if(start->next==NULL)//if only one element in link list
    {
        cout<<start->value<<endl;
        return;
    }
    while(temp->next!=NULL )
    {
        cout<<temp->value<<" ";
        if(start->value==(temp->next)->value){//if circular link list
            cout<<endl;
            flag++;
        return;}
        temp=temp->next;
    }
    if(flag==0)
    cout<<temp->value<<endl;
    
}

int main()
{
    stack s(100);
    int a6,b6,c6;
    a6=10;
    b6=20;
    c6=39;
    a6=a6+b6;
    c6=c6+b6;
    b6=a6-b6;
    c6=c6+c6;
    a6=a6-b6;
    b6=a6+c6;
    a6=40;
    b6=20;
    c6=19;
    a6=a6+b6-c6;
    b6=9- 4;
    c6=10+ 1- 8;
    
      long long int t=0,i,j,input,x,y,z;
    char c;
    node *temp=start;
    cin>>t;
    for(j=0;j<t;j++)//for taking inputs
    {
        cin>>c;
        if(c=='I')
        {
            cin>>input;
            if(input==0)
            {
                cin>>x;
            
                insert1(x);
                
                //display();
            }
            else if(input==1)
            {
                cin>>y>>x;
               insert2(x,y);
                
                //display();
            }
            else if(input==2)
            {
                cin>>z>>y>>x;
                
                insert3(x,y,z);
                //display();
                
            }
            else cout<<"error in input";
        }
        else if(c=='U')
        {
            cin>>x>>y;
            linker(x,y);
        }
        else
        {
            
            continue;
        }
    }
    cout<<circular<<endl;//line 1 of output
    

      long long int actual[10000],actual2[10000];//actual2 array is for frequency  storing 
      long long int k=0;
      long long int c1=0,c2=0;
    for(i=0;i<counter;i++)//to create an array containing only elements with multiple references
    {
        if(frequency[i] <= 1)
        continue;
        else {c1++;
        c2=1;
        actual[k]=multi_point_nodes[i];
        actual2[k]=frequency[i];
        k++;
        
        }
    }
    if(c2==0)//if zero nodes have multiple links
    {
        cout<<0<<endl;//line 2 of output
        display();//line 3 of output
        
    }
    else 
    {
        cout<<k<<endl;//line 2 of output
        //sorting the array in ascending order of values
         for(i=0;i<k;i++){

              long long int min=actual[i];
              long long int temp=0,p=i;
            for(j=i+ 1;j<k;j++)
            {
                if(actual[j] < min)
                {
                    p=j;
                    min=actual[j];
                }
            }
            temp=actual[i];
            actual[i]=actual[p];
            actual[p]=temp;
            temp=actual2[i];
            actual2[i]=actual2[p];
            actual2[p]=temp;
        }
        for(i=0;i<k;i++)
        cout<<actual[i]<<" ";//line 3 of output
        
        cout<<endl;
        for(i=0;i<k;i++)
        cout<<actual2[i]<<" ";//line 4 of output
        
    }

    return 0;
}
void maine()
{
	int a[100], n, i,j,k ;
	cout<<"enetr the length of array";
	cin>>n;
	cout<<"enetr the elements of the array";
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	{int c=i+1;
	for(j=c ;j<n;j++)
	{
		if(a[i]==a[j])
		{
			for(k=j;k<n;k++)
			{
				a[k]=a[k+1];
			}
			n=n-1;
			i=i-1;
		}
	}
	}
	cout<<"elements of array are ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" "; 
	}
	return ;
}