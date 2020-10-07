#include <iostream>
#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;
 int multi_point_nodes[10000],circular=0;
int frequency[10000],counter=0;
class node
{
    public:
     int value;
     int freq=0;
    node *next;
    void newer(int x0,int f);
    void insert1(  int n);
    void insert2(  int x0, int y0);
    void insert3(  int x0, int y0, int z0);
    void update( int x0,  int f);
    void linker(   int x0,   int p0);
    void display();
};

void node::newer(int x0, int f)
{
    multi_point_nodes[counter]=x0;
    frequency[counter]=f;
    counter++;
}
void node::update( int x0,  int f)
{
    for(  int i0=0;i0<counter;i0++)
    {
        if(x0==multi_point_nodes[i0]){
        frequency[i0]=f;
        }
    }
}
node *start=NULL;
void node::insert1(  int n)
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
void node::insert2(  int x0, int y0)
{
    node *temp=start;
    int count=0,pos;
     
    while(temp!=NULL)
    {
        count++;
        if(temp->value==y0)
        {
            
            node *ptr=new node();
            ptr->value=x0;
            ptr->freq++;
            ptr->next=temp->next;
            temp->next=ptr;
            newer(ptr->value,ptr->freq);
            return ;
        }
        else if(temp->value==x0)
        {
           
            pos=count;
            break;
        }
        else temp=temp->next;
    }
    count=1;
    node *nodietemp=start;
    if(start->value==x0)
    {
        node *ptr=new node();
            ptr->value=y0;
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
    ptr->value=y0;
    ptr->freq=ptr->freq+1;
    newer(ptr->value,ptr->freq);
    ptr->next=nodietemp->next;
    nodietemp->next=ptr;
    
}
void node::insert3(  int x0,  int y0,  int z0)
{
    node *ptr=new node();
    node *temp=start;
    ptr->value=x0;
    ptr->freq++;
    newer(ptr->value,ptr->freq);
    ptr->next=NULL;
      long long int count=-1;
    while(temp!=NULL)
    {
        if(temp->value==z0 )
        {
            break;
        }
        else temp=temp->next;
    }
    node *first=temp;
    while(temp!=NULL)
    {
        count++;
        if(temp->value==y0)
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

void node::linker(   int x0,   int p0){
    node *temp= start;
    int count=0;
    while(temp!=NULL || (temp)->value==start->value)
    {
        if(temp->value==x0)
            break;
        else temp=temp->next;
    }
    node *first_element=temp;
    while(count!=p0)
    {
        if(temp->next==NULL)
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
void node::display()
{
    node *temp=start;
      int flag=0;
    if(start==NULL)
    {
    
    return;
    }
    if(start->next==NULL)
    {
        cout<<start->value<<endl;
        return;
    }
    while(temp->next!=NULL )
    {
        cout<<temp->value<<" ";
        if(start->value==(temp->next)->value)
		{
			printf("\n");
           
            flag++;
        return;}
        temp=temp->next;
    }
    if(flag==0)
    cout<<temp->value<<endl;
    
}
int main()
{
    node l;
      int t0=0,i0,j0,input,x0,y0,z0;
    char c;
    node *temp=start;
    scanf("%d",&t0);
    j0=0;
    while(j0<t0)
    {
    
       cin>>c;
        if(c=='U')
        {
            scanf("%d %d",&x0,&y0);
          
            l.linker(x0,y0);
        }
        else if(c=='I')
        {
        	
            cin>>input;
            if(input==0)
            {
            	scanf("%d",&x0);
               
            
                l.insert1(x0);
                
                
            }
            else if(input==1)
            {
            	scanf("%d %d",&y0,&x0);
               
               l.insert2(x0,y0);
                
                
            }
            else if(input==2)
            {
            	scanf("%d %d %d",&z0,&y0,&x0);
               
                
                l.insert3(x0,y0,z0);
                
                
            }
            else printf("error in input") ;
			
        }
        else
        {
            j0++;
            continue;
        }
        j0++;
    }
    printf("%d",circular);
    printf("\n");
   
    
 int actual[9999];
 int actual2[9999], k0=0;
      int c10=0;
      int c20=0;
      i0=0;
      while(i0<counter)
    {
        if(frequency[i0] > 1)
        {
            c10++;
        c20=1;
        actual[k0]=multi_point_nodes[i0];
        actual2[k0]=frequency[i0];
        k0++;
        }
        
        else {
            i0++;
        continue;
        }
        i0++;
    }
    if(c20!=0)
    {
    		printf("%d",k0);
    	printf("\n");
        
        i0=0;
        while(i0<k0)
         {

              int min=actual[i0];
             int temp=0,p0=i0;
             j0=i0+ 1;
             while(j0<k0)
            
            {
                if(actual[j0] < min)
                {
                    p0=j0;
                    min=actual[j0];
                }
                j0++;
            }
           /* actual[i0]=actual[i0]+actual[p0];
            actual[i0]=actual[i0]-actual[p0];
            actual[p0]=actual[i0]-actual[p0];
            */
            temp=actual[i0];
            actual[i0]=actual[p0];
            actual[p0]=temp;
            
            temp=actual2[i0];
            actual2[i0]=actual2[p0];
            actual2[p0]=temp;
            i0++;
        }
        i0=0;
        while(i0<k0)
       {
        printf("%d",actual[i0]);
        i0++;
       }
       
        printf(" ");
       printf("\n");
       i0=0;
        while(i0<k0){
        printf("%d",actual2[i0]);
        i0++;
        }
        printf(" ");
    }
    else 
    {
        printf("0");
    	printf("\n");
        l.display();
    }

    return 0;
}
