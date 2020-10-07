#include <iostream>
#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<string.h>
#include<stdio.h>
/*#include <iostream>
#include <cstring>
using namespace std;

struct node
{   char data;
    node *next;
    node *mul;
}*head = NULL;

int flag = 0, count1 = 0;
int fr[1001];
int x = 0, y = 0;
int f = -999;
void print(node *head)
{
    if(head!=NULL)
    {
        if(flag == 1)
            cout<<"1\n";
        else
            cout<<"0\n";
       node *temp=head;
       node *temp2=temp->mul;
       while(temp2->mul!=NULL)
       {
           if(temp2->next==temp->next)
           {
               fr[(int)temp->next->data]++;
           }
           temp2=temp2->mul;
       }
       for(int i = 0; i < 1001; i++)
       {
           if(fr[i]>=2)
            count1++;
       }
       cout<<count1<<endl;
       if(count1==0)
        {
            node *temp = head;
            while(temp!=NULL)//||temp->next!=head)
            {
                cout<<temp->data<<" ";
                temp = temp->next;

            }
        }
        else if(count1>0)
        {
            for(int i = 0; i < 1001; i++)
            {
                if(fr[i]>=2)
                    cout<<fr[i]<<" ";
            }
            cout<<endl;
        }
    }
}
char t = 'z';
int main()
{
    int nop;
    string arr[1000];
    string s;
    cin>>nop;
    cin.ignore();
    int k = 0;
    if(nop>=1 && nop <= 1000)
*/
using namespace std;
class Node
{
    int data;
    Node* next;
    Node* head=NULL;
    bool isCircular=false;
    int *table=new int[5000];
    Node* NodeTable[5000];
    int N=0;
    public:
        /*
        #include <iostream>
#include <cstring>
using namespace std;

struct node
{   char data;
    node *next;
    node *mul;
}*head = NULL;

int flag = 0, count1 = 0;
int fr[1001];
int x = 0, y = 0;
int f = -999;
void print(node *head)
{
    if(head!=NULL)
    {
        if(flag == 1)
            cout<<"1\n";
        else
            cout<<"0\n";
       node *temp=head;
       node *temp2=temp->mul;
       while(temp2->mul!=NULL)
       {
           if(temp2->next==temp->next)
           {
               fr[(int)temp->next->data]++;
           }
           temp2=temp2->mul;
       }
       for(int i = 0; i < 1001; i++)
       {
           if(fr[i]>=2)
            count1++;
       }
       cout<<count1<<endl;
       if(count1==0)
        {
            node *temp = head;
            while(temp!=NULL)//||temp->next!=head)
            {
                cout<<temp->data<<" ";
                temp = temp->next;

            }
        }
        else if(count1>0)
        {
            for(int i = 0; i < 1001; i++)
            {
                if(fr[i]>=2)
                    cout<<fr[i]<<" ";
            }
            cout<<endl;
        }
    }
}
char t = 'z';
int main()
{
    int nop;
    string arr[1000];
    string s;
    cin>>nop;
    cin.ignore();
    int k = 0;
    if(nop>=1 && nop <= 1000)
        */
    int* getTable()
    {
        return table;
    }
    Node()
    {
        for(int i=0;i<1001;i++) {table[i]=0;};
        for(int i=0;i<1001;i++){NodeTable[i]=NULL;}
    }

    void i0(int x0)
    {
        Node* temp2=new Node;
        temp2->data=x0;
        temp2->next=NULL;
        NodeTable[x0]=temp2;
        N++;

        if(head==NULL)
        {
            head=temp2;
            table[head->data]=0;
            return;
        }

        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=temp2;
    }
    /*
    #include <iostream>
#include <cstring>
using namespace std;

struct node
{   char data;
    node *next;
    node *mul;
}*head = NULL;

int flag = 0, count1 = 0;
int fr[1001];
int x = 0, y = 0;
int f = -999;
void print(node *head)
{
    if(head!=NULL)
    {
        if(flag == 1)
            cout<<"1\n";
        else
            cout<<"0\n";
       node *temp=head;
       node *temp2=temp->mul;
       while(temp2->mul!=NULL)
       {
           if(temp2->next==temp->next)
           {
               fr[(int)temp->next->data]++;
           }
           temp2=temp2->mul;
       }
       for(int i = 0; i < 1001; i++)
       {
           if(fr[i]>=2)
            count1++;
       }
       cout<<count1<<endl;
       if(count1==0)
        {
            node *temp = head;
            while(temp!=NULL)//||temp->next!=head)
            {
                cout<<temp->data<<" ";
                temp = temp->next;

            }
        }
        else if(count1>0)
        {
            for(int i = 0; i < 1001; i++)
            {
                if(fr[i]>=2)
                    cout<<fr[i]<<" ";
            }
            cout<<endl;
        }
    }
}
char t = 'z';
int main()
{
    int nop;
    string arr[1000];
    string s;
    cin>>nop;
    cin.ignore();
    int k = 0;
    if(nop>=1 && nop <= 1000)
    */

    void i1(int y0,int x0)
    {
        N++;
        if(Search(y0))
            insafter(y0,x0);
        else
            insbefore(y0,x0);
    }


    void i2(int x0,int y0,int z0)
    {
       Node* temp2=new Node;
       temp2->data=z0;
       temp2->next=NULL;
       NodeTable[z0]=temp2;
       int distance=0;
       Node* temp=head;
       while(temp->data!=x0)
       {
        temp=temp->next;
       }
       Node* Initial=temp;
       while(temp->data!=y0)
       {
        temp=temp->next;
        distance++;
       }
       distance/=2;
       while(distance!=0)
       {
        Initial=Initial->next;
        distance--;
       }
       temp2->next=Initial->next;
       Initial->next=temp2;
       N++;
    }

    bool Search(int x0)
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data==x0)
            {
                return true;
            }
            temp=temp->next;
        }
        if(temp==NULL)
            return false;

    }

    void print()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    void u(int x0,int p)
    {
        if(Search(x0)==false)
        {
            return;
        }

        Node* temp=NodeTable[x0];
    	while(p!=0)
    	{
    		if(temp->next==NULL)
    		{
    		    temp->next=head;
    		    temp=head;
        	    isCircular=true;
        	    p--;
    		}
    		else
    		{
    		    temp=temp->next;
    		    p--;
    		}
        }
    	NodeTable[x0]->next=temp;
    }

    void insbefore(int y0,int x0)
    {
        Node* temp=new Node;
        temp->data=y0;
        temp->next=NULL;
        NodeTable[y0]=temp;
    	if(head->data==x0)
    	{
            temp->next=head;
            head=temp;
            return;
        }
        Node* temp2=head;
        while(temp2->next->data!=x0)
        {
            temp2=temp2->next;
        }
        temp->next=temp2->next;
        temp2->next=temp;
    }

    void insafter(int y0,int x0)
    {
        Node* temp=new Node;
        temp->data=x0;
        temp->next=NULL;
        NodeTable[x0]=temp;
        Node* temp2=head;
        while(temp2->data!=y0)
        {
            temp2=temp2->next;
        }
        temp->next=temp2->next;
        temp2->next=temp;
    }




    void Gentable()
    {
        for(int i=1;i<1001;i++)
        {
           if(NodeTable[i]!=NULL)
           {
                if(NodeTable[i]->next!=NULL)
                {
                    table[NodeTable[i]->next->data]++;
                }
           }
        }
    }

    void printtable()
    {
        for(int i=1;i<10;i++)
        {
            cout<<i<<" "<<table[i]<<endl;
        }
    }
    bool circular()
    {
        return isCircular;
    }
    int len()
    {
        return N;
    }
};
/*
#include <iostream>
#include <cstring>
using namespace std;

struct node
{   char data;
    node *next;
    node *mul;
}*head = NULL;

int flag = 0, count1 = 0;
int fr[1001];
int x = 0, y = 0;
int f = -999;
void print(node *head)
{
    if(head!=NULL)
    {
        if(flag == 1)
            cout<<"1\n";
        else
            cout<<"0\n";
       node *temp=head;
       node *temp2=temp->mul;
       while(temp2->mul!=NULL)
       {
           if(temp2->next==temp->next)
           {
               fr[(int)temp->next->data]++;
           }
           temp2=temp2->mul;
       }
       for(int i = 0; i < 1001; i++)
       {
           if(fr[i]>=2)
            count1++;
       }
       cout<<count1<<endl;
       if(count1==0)
        {
            node *temp = head;
            while(temp!=NULL)//||temp->next!=head)
            {
                cout<<temp->data<<" ";
                temp = temp->next;

            }
        }
        else if(count1>0)
        {
            for(int i = 0; i < 1001; i++)
            {
                if(fr[i]>=2)
                    cout<<fr[i]<<" ";
            }
            cout<<endl;
        }
    }
}
char t = 'z';
int main()
{
    int nop;
    string arr[1000];
    string s;
    cin>>nop;
    cin.ignore();
    int k = 0;
    if(nop>=1 && nop <= 1000)
*/
int main()
{
    Node A;
    int N;
    cin>>N;
    char a0;
    int b0;
    for(int i=0;i<N;i++)
    {
        cin>>a0;
        cin>>b0;
        if(a0=='I' && b0==0)
        {
            int x0;
            cin>>x0;
            A.i0(x0);
        }
        else if(a0=='I' && b0==1)
        {
            int x0,y0;
            cin>>x0>>y0;
            A.i1(x0,y0);
        }

        else if(a0=='I' && b0==2)
        {
            int x0,y0,z0;
            cin>>x0>>y0>>z0;
            A.i2(x0,y0,z0);
        }
        else if(a0=='U')
        {
            int p;
            cin>>p;
            A.u(b0,p);
        }

    }
    A.Gentable();
    int* ansTable=A.getTable();
    int countMultiple=0;
    if(A.circular())
        cout<<1<<endl;
    else
        cout<<0<<endl;
    for(int i=1;i<=1000;i++)
    {
        if(ansTable[i]>=2)
        {
            countMultiple++;
        }
    }
    if(countMultiple==0)
    {
        cout<<"0"<<endl; A.print();
    }
    else
    {
            cout<<countMultiple<<endl;
        for(int i=1;i<=1000;i++)
        {
            if(ansTable[i]>=2) cout<<i<<" ";
        }
        cout<<endl;
        for(int i=1;i<=1000;i++)
        {
            if(ansTable[i]>=2) cout<<ansTable[i]<<" ";
        }
    }
    cout<<endl;
}
//Node* temp=NodeTable[x];
    //	while(p!=0)
    	/*{
    		if(temp->next==NULL)
    		{
    		    temp->next=head;
    		    temp=head;
        	    isCircular=true;
        	    p--;
    		}
    		else
    		{
    		    temp=temp->next;
    		    p--;
    		}
        }

    	NodeTable[x]->next=temp;
    }*/
    /*
    #include <iostream>
#include <cstring>
using namespace std;

struct node
{   char data;
    node *next;
    node *mul;
}*head = NULL;

int flag = 0, count1 = 0;
int fr[1001];
int x = 0, y = 0;
int f = -999;
void print(node *head)
{
    if(head!=NULL)
    {
        if(flag == 1)
            cout<<"1\n";
        else
            cout<<"0\n";
       node *temp=head;
       node *temp2=temp->mul;
       while(temp2->mul!=NULL)
       {
           if(temp2->next==temp->next)
           {
               fr[(int)temp->next->data]++;
           }
           temp2=temp2->mul;
       }
       for(int i = 0; i < 1001; i++)
       {
           if(fr[i]>=2)
            count1++;
       }
       cout<<count1<<endl;
       if(count1==0)
        {
            node *temp = head;
            while(temp!=NULL)//||temp->next!=head)
            {
                cout<<temp->data<<" ";
                temp = temp->next;

            }
        }
        else if(count1>0)
        {
            for(int i = 0; i < 1001; i++)
            {
                if(fr[i]>=2)
                    cout<<fr[i]<<" ";
            }
            cout<<endl;
        }
    }
}
char t = 'z';
int main()
{
    int nop;
    string arr[1000];
    string s;
    cin>>nop;
    cin.ignore();
    int k = 0;
    if(nop>=1 && nop <= 1000)
    */
