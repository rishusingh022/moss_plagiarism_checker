#include<bits/stdc++.h>
using namespace std;
void peek(int arr[][3], int str, int stc, int diff)
{
	int k;
	for(k=1;k<=arr[0][2];k++)
	{
		if(arr[k][0]==str)
		{
			if(arr[k][1]==stc)
			{
				cout<<arr[k][0]<<" "<<arr[k][1]<<" "<<arr[k][2]<<" "<<diff<<endl;
				break;
			}
		}
	}
}

struct node
{
    int input;
    node *then=NULL;
};
int tocrc=0;
int thencountarr[1000]={0};
class problem{
    private:
    protected:
    public:
    void to_print(node *top)
{
    for(node *ptr=top;ptr!=NULL;ptr=ptr->then)
    {
       cout<<ptr->input<<" ";
    }
    cout<<endl;
}
void function0(node *&top, int x)
{
    node *p=new node;
    p->input=x;
    if(top==NULL)
    {
        top=p;
        return;
    }
    node *ptr= new node;
    ptr=top;
    while(ptr->then!=NULL)
    {
        ptr=ptr->then;
    }
    ptr->then=p;
}
void function3(node *&top, int x, int p)
{
    node *ptr= new node;
    ptr=top;
    node *temp=new node;
    for(;ptr!=NULL and ptr->input!=x;ptr=ptr->then){}
    thencountarr[ptr->then->input]--;
    temp=ptr;
    int i=0;
    while(i<p)
    {
        if(temp->then==NULL)
        {
            temp->then=top;
            tocrc=1;
        }
        temp=temp->then;
        i++;
    }
    ptr->then=temp;
    thencountarr[temp->input]++;
}
void insertBeg(node *&top, int val)
{
    node *p=new node;
    p->input=val;
    if(top==NULL)
    {
        top=p;
        return;
    }
    p->then=top;
    top=p;
}
void input_Output()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
void function2(node *&top, int z, int y, int x)
{
    node *pointer= new node;
    pointer=top;
    int check=0;
    int beg=0, end=0;
    for(;pointer!=NULL and pointer->input!=z;pointer=pointer->then){
        check++;
    }
    beg=check;
    for(;pointer!=NULL and pointer->input!=y;pointer=pointer->then){
        check++;
    }
    end=check;
    node *p=new node;
    p->input=x;
    int mid=(beg+end)/2;
    pointer=top;
    for(int i=0; i<mid; i++)
    {
        pointer=pointer->then;
    }
    p->then=pointer->then;
    pointer->then=p;
}

};
int main()
{
	int n,m,non,stc,str,i,diff,x,k;
	diff=k=1;
	cin>>n;
	cin>>m;
	cin>>non;
	int arr[non+1][3];
	arr[0][0]=n;
	arr[0][1]=m;
	arr[0][2]=non;
	for(i=1;i<=non;i++)
	{
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	cin>>str>>stc;
	peek(arr,str,stc,diff);
	x=1;
	while(x<=(m*n))
	{
		for(i=0;i<k;i++)
		{
			str++;
			x++;
			diff=1;
			peek(arr,str,stc,diff);
		}
		for(i=0;i<k;i++)
		{
			stc++;
			x++;
			diff=2;
			peek(arr,str,stc,diff);
		}
		k++;
		for(i=0;i<k;i++)
		{
			str--;
			x++;
			diff=3;
			peek(arr,str,stc,diff);
		}
		for(i=0;i<k;i++)
		{
			stc--;
			x++;
			diff=4;
			peek(arr,str,stc,diff);
		}
		k++;
	}
	return 0;
}
