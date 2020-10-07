#include<iostream>
#include<sstream>
using namespace std;

int flag=0;
//static int m=0;
int freq[1001]={1};

class node
{
	public:
		int data;
		node *next;
}*head=NULL;

node *insert(int c)
{
	node *temp=new node;
	temp->data=c;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		node *temp1=head;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
	return head;
}

node *insertany(int y, int x)
{
	node *temp1=head;
	while(temp1->next!=NULL)
	{
		if(temp1->data==y)
		{
			break;
		}
		temp1=temp1->next;
	}
	if(temp1->data==y)
	{
		node *temp=new node;
		temp->data=x;
		temp->next=temp1->next;
		temp1->next=temp;
		return head;
	}
	temp1=head;
	while(temp1->next!=NULL)
	{
		if(temp1->next->data==x)
		{
			break;
		}
		temp1=temp1->next;
	}
	if(temp1->data==x)
	{
		node *temp=new node;
		temp->data=y;
		temp->next=temp1->next;
		temp1->next=temp;
	}
	return head;
}

node *insertb2(int z,int y,int x)
{
	int c=0;
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	node *temp1=head;
	while(temp1->data!=z)
	{
		temp1=temp1->next;
	}
	if(temp1->next->data==y)
	{
		temp->next=temp1->next;
		temp1->next=temp;
		return head;
	}
	else
	{
		node *temp2=temp1;
		while(temp2->next!=NULL)
		{
			c++;
			if(temp2->next->data==y)
			{
				break;
			}
			temp2=temp2->next;
		}
		for(int i=0;i<c/2;i++)
		{
			temp1=temp1->next;
		}
		temp->next=temp2;
		temp1->next=temp;
		return head;
	}
}

/*void countn(node *temp1)
{
    r[m]=temp1->data;
	m++;
	//cout<<m<<" "<<r[m]<<endl;
}*/

void link(int x,int p){
    node *temp=head;
    while(temp->data!=x){
        temp=temp->next;
    }
    int k=p;
    node *temp1=temp;
    while(k>0){
        if(temp1->next==NULL){
            flag=1;
            temp1->next=head;
        }
        temp1=temp1->next;
        k--;
    }
    freq[temp->next->data]--;
    temp->next=temp1;
    freq[temp->next->data]++;
    //return head;
}

void print(node *head)
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void disp()
{
	cout<<flag<<endl;

    int count=0;
    for(int i=1;i<=1000;i++){
        if(freq[i]>=2){
            count++;
        }
    }
    cout<<count<<endl;
    if(count==0){
        print (head);
    }
    else{
        for(int i=1;i<=1000;i++){
            if(freq[i]>=2){
                cout<<i<<" ";
            }
        }
        cout<<endl;
        for(int i=1;i<=1000;i++){
            if(freq[i]>=2){
                cout<<freq[i]<<" ";
            }
        }
    }
}

int main()
{
	int n; char s,s1,x1,y1,z1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s=='I')
		{
			cin>>s1;
			if(s1=='0')
			{
				cin>>x1;
				int x=x1-'0';
				head=insert(x);
			}
			else if(s1=='1')
			{
				cin>>y1>>x1;
				int y=y1-'0';
				int x=x1-'0';
				head=insertany(y,x);
			}
			else if(s1=='2')
			{
				cin>>z1>>y1>>x1;
				int z=z1-'0';
				int y=y1-'0';
				int x=x1-'0';
				head=insertb2(z,y,x);
			}
		}
		else if(s=='U')
		{
			cin>>x1>>y1;
			int x=x1-'0';
			int p=y1-'0';
			link(x,p);
		}
	}
	disp();
}
