#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;
struct node
{
    int value;
    node *next=NULL;
};
node *start=NULL;
void add_begin(int n)
{   node *temp = new node;
    temp->value=n;
    temp->next=NULL;
    if(start == NULL)
    {
        start=temp;
        return;
    }
    
    temp->next=start;
    start=temp;
    return;
}

void add_end(int n)
{
    node *looper=new node;
    looper=start;
    node *temp=new node;
    temp->value=n;
    if(start==NULL)
    {
        temp->value=n;
        start=temp;
        start->next=NULL;
        return;
    }
    while(looper->next!=NULL)
    {
        looper=looper->next;
    }
    looper->next=temp;
    temp->next=NULL;
    
}

void add_specificpos(int n,int p)
{   int i=1;
    node *temp=new node;
    if(start==NULL)
    {
        start->value=n;
        start->next=NULL;
        return;
    }
    temp=start;
    node *nodie=new node;
    nodie->value=n;
    nodie->next=NULL;
    if(p==1)
    {

        nodie->next=temp;
        start=nodie;
        return;
    }
    while(temp!=NULL && i<p-1)
    {
        i++;
        temp=temp->next;
    }
    
    nodie->next=temp->next;
    temp->next=nodie;
}
void delete_first()
{
    node *temp=new node;
    temp =start;
    start=temp->next;
    
    temp->next=NULL;
    temp=NULL;
    delete(temp);
}
void delete_end()
{
    node *temp=new node;
    temp=start;
    if(start->next==NULL)
    {
        start=NULL;
        return ;
    }
    while((temp->next)->next!=NULL)
    {
        temp=temp->next;
    }
    node *nodie=new node;
    nodie=temp->next;
    delete(nodie);
    temp->next=NULL;
}
void delete_specificnode(int pos)
{
    node *temp=new node;
    temp=start;
    int count=1;
    if(pos==1)
    {
        node *nodie=start;
        start=start->next;
        delete(nodie);
        nodie->next=NULL;
        nodie=NULL;
        return;
    }cout<<"reached";
    while(temp!=NULL && count<pos-1)
    {
        count++;
        temp=temp->next;
    }
    cout<<"here";
        node *nodie=new node;
        nodie=temp->next;
        temp->next=(temp->next)->next;
        delete(nodie);
        nodie->next=NULL;
        nodie=NULL;
    
}
void display_posfromhead(int n)
{
    node *temp=new node;
    temp= start;
    int count =0;
    while(temp!=NULL && temp->value!=n)
    {
        temp=temp->next;
        count++;
    }
    if(temp->value=n)
    cout<<"the position from head is"<<count;
    else cout<<"element not found";
}
void display()
{   node  *temp;
    temp=start;
    while(temp!=NULL)
    {
        cout<<temp->value<<"  ";
        temp=temp->next;
    }
}
int main()
{   node h;
	int i0;
	int j0;
	int n0;
    int arr[10000],count0[50];
    int k0,count20[50];
    
    int l=0 , index0=0 ;
    int index1=0,length=0;
    string s0,s2;
    string abcd0;
    string abcd1;
    
     cin>>s0;
     scanf("%d",&n0);
    
   i0=0;
   while(i0<n0)
  {
  scanf("%d",&arr[i0]);
      i0++;
  }
    abcd0="abcdefghijklmnopqrstuvwxyz";
    abcd1=abcd0;
    count0[40]={0};
    
    for(i0=0; s0[i0]!='\0';i0++)
    {
        j0=0;
        while(j0<26)
        
        {
            if(s0[i0]==abcd0[j0])
            {
                count0[j0]++;
            }
            j0++;
        }
        
    }
    
    k0=0;
    for(i0=0; s0[i0]!='\0';i0++)
    {
        
        j0=0;
        while(j0<26)
        {
            if(s0[i0]!=abcd0[j0])
            {
                j0++;
                continue;
            }
            else
            {
                cout<<abcd0[j0]<<" "<<count0[j0]<<" ";
                s2 = s2 + abcd0[j0];
                count20[k0++]=count0[j0];
                int length2=abcd0.size();
                for(l=j0;l<length2;l++)
                {
                    abcd0[l]=abcd0[l+1];
                    count0[l]=count0[l+1];
                }
                length2--;
            }
            j0++;
        }
    }
    length=k0;
    printf("\n");
   

   
  
    l=0;
    while(l<n0)
    
    {
        length=s2.size();
        i0=0;
        while(i0<length)
        
        {
            if(count20[i0]==arr[l] && count20[i0+1]==arr[l])
            {
                index0=i0+1;
                break;
            }
            else if(count20[i0]!=arr[l])
            {
                i0++;
                continue;
                
            }
            else 
            {
                index0=i0;
                break;
            }
        }
    
        i0=length- 1;
        while(i0>=0)
        
        {
           if(count20[i0]==arr[l] )
           {
                index1=i0;
               break;
            }
            i0--;
        }
        if(index1!=index0)
        {
            i0=index0+ 1;
            while(i0<index1)
            
            {
                        if(count20[i0]>arr[l])
                        {
                            length=s2.size();
                            s2[length]=s2[i0];
                            count20[length]=count20[i0];
                            for(j0=i0;j0<=length;j0++)
                            {
                                s2[j0]=s2[j0+1];
                            }
                            
                            for(j0=i0;j0<length;j0++)
                            {
                                count20[j0]=count20[j0+1];
                            }
                            
                            index1--;
                            
                        }
                        else if(count20[i0]<arr[l])
                        {
                            string x=s2;
                            x[0]=s2[i0];
                            for(j0=0;j0<i0;j0++)
							{
                            x[j0+1]=s2[j0];
                            
                            }
                            for(j0=i0+1;j0<length;j0++){
                            x[j0]=s2[j0];
                            
                            }
                            s2=x;
                            int count3[30];
                            count3[0]=count20[i0];
                            for(j0=0; j0<i0;j0++)
                            {
                                count3[j0+1]=count20[j0];
                            }
                            for(j0=i0+1;j0<length;j0++)
                            {
                                count3[j0]=count20[j0];
                            }
                            for(j0=0;j0<length;j0++)
                            {
                                count20[j0]=count3[j0];
                            }
                            i0++;
                            
                            
                        }
                        else {i0++;
                        continue;
                        }
            }
             i0=0;
             while(i0<length)
            {
                cout<<s2[i0]<<" "<<count20[i0]<<" ";
                i0++;
            }
            printf("\n");
           
        }
        else 
        {
            i0=0;
            while(i0<length)
            
            {
            
                cout<<s2[i0]<<" "<<count20[i0]<<" ";
                i0++;
            }
            printf("\n");
           
            continue;
            
        }
        l++;
    }
    return 0;
}
