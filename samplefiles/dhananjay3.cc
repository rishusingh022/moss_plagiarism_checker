#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node1
{
    int valnum;
    node1 *after=NULL;
};
class node{
    public:
    int data;
    node*next=NULL;
    node*pre=NULL;
};
int isround=0;
int freenumarr[1000]={0};
class answer{
    
    private:
    
    protected:
    
    public:
        void lastinsert(node1 *&h, int x);
        
        void show(node1 *h);

        void insertBeg(node1 *&h, int val);
        
        void misinsert(node1 *&h, int x, int p);

        void midinsert(node1 *&h, int z, int y, int x);
        
        void insertalternate(node1 *&h, int y, int x);

        void valnum_Output()
        {
            #ifndef ONLINE_JUDGE
            freopen("valnum.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
            #endif
        }
};
class demo
{
private:
    
protected:
    
public:
void firstinsert(node** head,int value)
{
    node* start=new node();
    start=*head;
    node* ptr = new node();
    ptr->data = value;
    if(*head==NULL)
    {
        ptr->next=ptr;
        ptr->pre=ptr;
        *head=ptr;
        
        
    }
    else
    {
        node*last;
        last= start->pre;
        last->next=ptr;
        ptr->pre=last;
        start->pre=ptr;
        ptr->next=start;
        *head=ptr;
        
    }
}
void insertlast(node** head,int value)
{
    node*start= new node();
    start=*head;
    node* ptr = new node();
    ptr->data = value;
    if(start==NULL)
    {
        ptr->next=ptr;
        ptr->pre=ptr;
        *head=ptr;
        
    }
    else
    {
        node*last;
        last= start->pre;
        last->next=ptr;
        ptr->pre=last;
        start->pre=ptr;
        ptr->next=start;
        
    }
}
void iafter_node(node** head,int term,int value)
{
    node*p;
    p=*head;
    node* ptr = new node();
    ptr->data = value;
    if(p==NULL)
    {
        cout<<"linked list is empty\n";
        return ;
    }
    else if(p->pre->data==term)
    {
        node*last;
        last= p->pre;
        last->next=ptr;
        ptr->pre=last;
        p->pre=ptr;
        ptr->next=p;
        *head = ptr;
        return ;
    }
    while(p->data!=term && p->next!=*head)
    {
        p=p->next;
    }
    if(p==*head)
    {
        cout<<"cannot insert as "<<term<<" not found\n";
    }
    else
    {
        node*q=p->next;
        q->pre=ptr;
        ptr->next=q;
        p->next=ptr;
        ptr->pre=p;
    }
}
void deletefirst(node** head)
{
    node*start =*head;
    if(start==NULL)
    {
        cout<<"node is empty\n";
        
    }
    else if(start->next==start)
    {
        delete(start);
        *head=NULL;
    }
    else
    {
        node*last;
        last= start->pre;
        last->next=start->next;
        start->next->pre=last;
        *head=start->next;
        delete(start);
    }
}
void dafter_node(node** head,int term)
{
    node*p;
    p=*head;
    if(p==NULL)
    {
        cout<<"linked list is empty\n";
        return ;
    }
    else
    {
        while(p->data!=term && p->next!=*head)
        {
            p=p->next;
        }
        if(p==*head)
        {
            cout<<"cannot insert as "<<term<<" not found\n";
        }
        else
        {
            p->pre->next=p->next;
            p->next->pre=p->pre;
            if(p==*head)
            {
                *head=p->next;
            }
            delete(p);
            
        }
            
    }
}
void search(node* head,int term)
{
    int count=1;
    int a=0;
    node* start=head;
    if(start==NULL)
    {
        cout<<"linked list is empty";
        return ;
    }
    else if(start->pre->data==term)
    {
        
            cout<<"element found at last node \n";
        
        return ;
    }
    else
    {
        while(start->data!=term && start->next!=head)
        {
            start=start->next;
            count++;
        }
        if(start->next==head)
        {
            cout<<"no node contains this elemet\n";
        }
        else
        {
            cout<<"element found at node "<<count<<'\n';
        }
    
    }
}
void checkpalindrone(node* head)
{
    int check=0;
    node*start=head;
    node*last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    while(start!=last && last->next!=start)
    {
        if(start->data==last->data)
        {
            start=start->next;
            last=last->pre;
        }
        else
        {
            check=1;
            break;
        }
    }
    if(check==0)
    {
        cout<<"linked list is palindrone";
    }
    else
    {
        cout<<"linked list is not palindrine";
    }
}
};
int32_t main()
{   answer f;
    f.valnum_Output();
    fastIO;
    node1 *h=NULL;
    int n;
    cin>>n;
    while(n--)
    {
        char funtion;
        cin>>funtion;
        if(funtion=='I')
        {
            int select;
            cin>>select;
            if(select==0)
            {
                int x;
                cin>>x;  
                f.lastinsert(h, x);
            }
            else if(select==1)
            {
                int x,y;
                cin>>y>>x;
                f.insertalternate(h, y, x);
            }
            else
            {
                int x,y,z;
                cin>>z>>y>>x;
                f.midinsert(h, z, y, x);
            }

        }
        else
        {
            int x,p;
            cin>>x>>p;
            f.misinsert(h, x, p);
        }
    }
    cout<<isround<<'\n';
    int jyadanodecounter=0;
    std::vector<int> v1;
    for(int k=0; k<1000; k++)
    {
        if(freenumarr[k]>0)
        {
            jyadanodecounter++;
            v1.push_back(k);
        }
    }
    cout<<jyadanodecounter<<'\n';
    sort(v1.begin(), v1.end());
    if(jyadanodecounter==0)
    {
        f.show(h);
    }
    else
    {
        for(auto m : v1)
        {
            cout<<m<<" ";
        }
        cout<<'\n';
    }
    if(jyadanodecounter>0)
    {
        for(auto m : v1)
        {
            cout<<freenumarr[m]+1<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
void answer::lastinsert(node1 *&h, int x)
 {
    node1 *p=new node1;
    p->valnum=x;
    if(h==NULL)
    {
        h=p;
        return;
    }
    node1 *ptr= new node1;
    ptr=h;
    while(ptr->after!=NULL)
    {
        ptr=ptr->after;
    }
    ptr->after=p;
}
void answer::show(node1 *h)
{
            for(node1 *ptr=h;ptr!=NULL;ptr=ptr->after)
            {
               cout<<ptr->valnum<<" ";
            }
            cout<<'\n';
}
void answer::insertBeg(node1 *&h, int val)
{
    node1 *p=new node1;
    p->valnum=val;
    if(h==NULL)
    {
        h=p;
        return;
    }
    p->after=h;
    h=p;
}
void answer::insertalternate(node1 *&h, int y, int x)
{
    node1 *ptr=new node1;
    ptr=h;
    for(;ptr!=NULL and ptr->valnum!=y; ptr=ptr->after)
    {
       
    }
    if(ptr==NULL)
    {
        if(h->valnum==x)
        {
            insertBeg(h, y);
            return;
        }
        ptr=h->after;
        node1 *temp=new node1;
        temp=h;
        while(ptr!=NULL and ptr->valnum!=x)
        {
            ptr=ptr->after;
            temp=temp->after;
        }
        node1 *p=new node1;
        p->valnum=y;
        temp->after=p;
        p->after=ptr;
    }
    else
    {
        node1 *p=new node1;
        p->valnum=x;
        p->after=ptr->after;
        ptr->after=p;
    }
}
void answer::misinsert(node1 *&h, int x, int p)
{
    node1 *ptr= new node1;
    ptr=h;
    node1 *temp=new node1;
    for(;ptr!=NULL and ptr->valnum!=x;ptr=ptr->after){}
    freenumarr[ptr->after->valnum]--;
    temp=ptr;
    int i=0;
    while(i<p)
    {
        if(temp->after==NULL)
        {
            temp->after=h;
            isround=1;
        }
        temp=temp->after;
        i++;
    }
    ptr->after=temp;
    freenumarr[temp->valnum]++;
}

void answer::midinsert(node1 *&h, int z, int y, int x)
{
    node1 *pointer= new node1;
    pointer=h;
    int check=0;
    int beg=0, end=0;
    for(;pointer!=NULL and pointer->valnum!=z;pointer=pointer->after){
        check++;
    }
    beg=check;
    for(;pointer!=NULL and pointer->valnum!=y;pointer=pointer->after){
        check++;
    }
    end=check;
    node1 *p=new node1;
    p->valnum=x;
    int mid=(beg+end)/2;
    pointer=h;
    for(int i=0; i<mid; i++)
    {
        pointer=pointer->after;
    }
    p->after=pointer->after;
    pointer->after=p;
}