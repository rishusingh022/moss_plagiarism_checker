#include<iostream>
using namespace std;

struct node
{
	int frequency;
	char letter;
	node *next;
};

void insertElement(node **start,char let, int fre)
{
	node *temp=new node();
	temp->frequency=fre;
	temp->letter=let;
	temp->next=NULL;
	if(*start==NULL)
	{
		*start=temp;
	}
	else
	{
		node *temp1=*start;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
}

void printFreq(const std::string&s2,int k, int freq[])
{
	for(int i=0;i<k;i++)
	{
		cout<<s2[i]<<" "<<freq[i]<<" ";
	}
}

void display(node **start)
{
	cout<<endl;
	node *r=*start;
	while(r!=NULL)
	{
		cout<<r->letter<<" "<<r->frequency<<" ";
		r=r->next;
	}
}

void rearrange(node **start, int comp)
{
	node *temp=*start;
	//int count=0;
	while(temp!=NULL && temp->frequency!=comp)
	{
		temp=temp->next;
		//cout<<"hi";
		//count++;
		//cout<<count;
	}
	node *last=*start;
	while(last->next!=NULL)
	{
		last=last->next;
	}
	if(temp==NULL)
	{
		display(start);
		return;
	}
	//cout<<endl<<temp->frequency;
	node *q=temp->next;
	node *temp2=NULL;
	while(q!=NULL)
	{
		if(q->frequency==comp)
		{
			temp2=q;
		}
		q=q->next;
	}
	//cout<<endl<<temp2->frequency;
	if(temp2==NULL)
	{
		display(start);
		return;
	}
	if(temp2==temp->next)
	{
		display(start);
		return;
	}
	node *p=temp->next;
	while(p!=temp2)
	{
		if(p->frequency!=temp->frequency)
		{
			if(p->frequency < temp->frequency)
			{
				node *q=p->next;
				temp->next=q;
				p->next=*start;
				*start=p;
				p=q;
			}
			else if(p->frequency > temp->frequency)
			{
				node *q=p->next;
				temp->next=q;
				last->next=p;
				p->next=NULL;
				last=p;
				p=q;
			}
		}
		else
		{
			temp=p;
			p=p->next;
		}
	}
	display(start);
}

int main()
{
	node *start=NULL;
	string s;
	int i,j,k=0;
	getline(cin,s);
	int n;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int length=s.length();
	int freq[length];
	for(i=0;i<length;i++)
	{
		freq[i]=1;
	}
	string s1=s;
	for(i=0;i<length;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if(s[i]==s1[j])
			{
				freq[k]=freq[k]+1;
				s1[j]='0';
			}
		}
		if(s1[i]!='0')
		{
			k=k+1;
		}
	}
	int t=0;
	string s2;
	for(i=0;i<length;i++)
	{
		if(s1[i]!='0')
		{
			s2[t]=s1[i];
			t++;
		}
	}
	cout<<s2;
	printFreq(s2,k,freq);
	for(i=0;i<k;i++)
	{
		insertElement(&start,s2[i],freq[i]);
	}
	/*node *r=start;
	while(r!=NULL)
	{
		cout<<r->letter<<endl;
		r=r->next;
	}*/
	for(i=0;i<n;i++)
	{
		int m=arr[i];
		rearrange(&start,m);
		
	}
	return 0;
}