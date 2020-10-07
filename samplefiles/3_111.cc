#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    int input;
    node *then=NULL;
};
int tocrc=0;
int thencountarr[1000]={0};
class takeinput{
    
    private:
    
    protected:
    
    public:
        void link(node *head)
        {
            for(node *ptr=head;ptr!=NULL;ptr=ptr->then)
            {
               cout<<ptr->input<<" ";
            }
            cout<<endl;
        }
        void link1()
        {
            #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
            #endif
        }
};
class create{
    
    private:
    
    protected:
    
    public:
        void create1(node *&head, int x)
        {
            node *p=new node;
            p->input=x;
            if(head==NULL)
            {
                head=p;
                return;
            }
            node *ptr= new node;
            ptr=head;
            while(ptr->then!=NULL)
            {
                ptr=ptr->then;
            }
            ptr->then=p;
        }
        void create20(node *&head, int x, int p)
        {
            node *ptr= new node;
            ptr=head;
            node *temp=new node;
            for(;ptr!=NULL and ptr->input!=x;ptr=ptr->then){}
            thencountarr[ptr->then->input]--;
            temp=ptr;
            int i=0;
            while(i<p)
            {
                if(temp->then==NULL)
                {
                    temp->then=head;
                    tocrc=1;
                }
                temp=temp->then;
                i++;
            }
            ptr->then=temp;
            thencountarr[temp->input]++;
        }
        void create2(node *&head, int val)
        {
            node *p=new node;
            p->input=val;
            if(head==NULL)
            {
                head=p;
                return;
            }
            p->then=head;
            head=p;
        }
        void create3(node *&head, int y, int x)
        {
            node *ptr=new node;
            ptr=head;
            for(;ptr!=NULL and ptr->input!=y; ptr=ptr->then)
            {
               
            }
            if(ptr==NULL)
            {
                if(head->input==x)
                {
                    create2(head, y);
                    return;
                }
                ptr=head->then;
                node *temp=new node;
                temp=head;
                while(ptr!=NULL and ptr->input!=x)
                {
                    ptr=ptr->then;
                    temp=temp->then;
                }
                node *p=new node;
                p->input=y;
                temp->then=p;
                p->then=ptr;
            }
            else
            {
                node *p=new node;
                p->input=x;
                p->then=ptr->then;
                ptr->then=p;
            }
        }
        void create4(node *&head, int z, int y, int x)
        {
            node *pointer= new node;
            pointer=head;
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
            pointer=head;
            for(int i=0; i<mid; i++)
            {
                pointer=pointer->then;
            }
            p->then=pointer->then;
            pointer->then=p;
        }
};
class linked{
    void linked1()
    {
        cout<<"linked lists created";
        
    }
    void linked2()
    {
        cout<<"linked lists created";
        
    }
    void linked3()
    {
        cout<<"linked lists created";
        
    }
    void linked4()
    {
        cout<<"linked lists created";
        
    }
    void linked5()
    {
        cout<<"linked lists created";
        
    }
    void linked6()
    {
        cout<<"linked lists created";
        
    }
    void linked7()
    {
        cout<<"linked lists created";
        
    }
    void linked8()
    {
        cout<<"linked lists created";
        
    }
    void linked9()
    {
        cout<<"linked lists created";
        
    }
    void linked10()
    {
        cout<<"linked lists created";
        
    }
    void linked11()
    {
        cout<<"linked lists created";
        
    }
    void linked12()
    {
        cout<<"linked lists created";
        
    }
    void linked13()
    {
        cout<<"linked lists created";
        
    }
    void linked14()
    {
        cout<<"linked lists created";
        
    }
    void linked15()
    {
        cout<<"linked lists created";
        
    }
    void linked16()
    {
        cout<<"linked lists created";
        
    }
    void linked17()
    {
        cout<<"linked lists created";
        
    }
    void linked18()
    {
        cout<<"linked lists created";
        
    }
    void linked19()
    {
        cout<<"linked lists created";
        
    }
    void linked20()
    {
        cout<<"linked lists created";
        
    }
    void linked21()
    {
        cout<<"linked lists created";
        
    }
    void linked22()
    {
        cout<<"linked lists created";
        
    }
    void linked23()
    {
        cout<<"linked lists created";
        
    }
    void linked24()
    {
        cout<<"linked lists created";
        
    }
    void linked25()
    {
        cout<<"linked lists created";
        
    }
    void linked26()
    {
        cout<<"linked lists created";
        
    }
    void linked27()
    {
        cout<<"linked lists created";
        
    }
    void linked28()
    {
        cout<<"linked lists created";
        
    }
    void linked29()
    {
        cout<<"linked lists created";
        
    }
    void linked30()
    {
        cout<<"linked lists created";
        
    }
    void linked31()
    {
        cout<<"linked lists created";
        
    }
    void linked32()
    {
        cout<<"linked lists created";
        
    }
};
int32_t main()
{   
    takeinput obj;
    create obj1;
    obj.link1();
    fastIO;
    node *head=NULL;
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
                obj1.create1(head, x);
            }
            else if(select==1)
            {
                int x,y;
                cin>>y>>x;
                obj1.create3(head, y, x);
            }
            else
            {
                int x,y,z;
                cin>>z>>y>>x;
                obj1.create4(head, z, y, x);
            }

        }
        else
        {
            int x,p;
            cin>>x>>p;
            obj1.create20(head, x, p);
        }
    }
    cout<<tocrc<<endl;
    int manynodecounter=0;
    std::vector<int> v1;
    for(int k=0; k<1000; k++)
    {
        if(thencountarr[k]>0)
        {
            manynodecounter++;
            v1.push_back(k);
        }
    }
    cout<<manynodecounter<<endl;
    sort(v1.begin(), v1.end());
    if(manynodecounter==0)
    {
        obj.link(head);
    }
    else
    {
        for(auto m : v1)
        {
            cout<<m<<" ";
        }
        cout<<endl;
    }
    if(manynodecounter>0)
    {
        for(auto m : v1)
        {
            cout<<thencountarr[m]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
