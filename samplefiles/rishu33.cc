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
class totakeinput{
    
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
        void input_Output()
        {
            #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
            #endif
        }
};
class toprint{
    
    private:
    
    protected:
    
    public:
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
        void function1(node *&top, int y, int x)
        {
            node *ptr=new node;
            ptr=top;
            for(;ptr!=NULL and ptr->input!=y; ptr=ptr->then)
            {
               
            }
            if(ptr==NULL)
            {
                if(top->input==x)
                {
                    insertBeg(top, y);
                    return;
                }
                ptr=top->then;
                node *temp=new node;
                temp=top;
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
int32_t main()
{   
    totakeinput obj;
    toprint obj1;
    obj.input_Output();
    fastIO;
    node *top=NULL;
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
                obj1.function0(top, x);
            }
            else if(select==1)
            {
                int x,y;
                cin>>y>>x;
                obj1.function1(top, y, x);
            }
            else
            {
                int x,y,z;
                cin>>z>>y>>x;
                obj1.function2(top, z, y, x);
            }

        }
        else
        {
            int x,p;
            cin>>x>>p;
            obj1.function3(top, x, p);
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
        obj.to_print(top);
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