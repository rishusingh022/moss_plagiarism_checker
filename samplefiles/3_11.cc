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
int thenccp=0;
int tocalarray[1000]={0};
class forinput{
    
    private:
    
    protected:
    
    public:
        void display(node *bottom)
        {
            for(node *ptr=bottom;ptr!=NULL;ptr=ptr->then)
            {
               cout<<ptr->input<<" ";
            }
            cout<<endl;
        }
        void output_Input()
        {
            #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
            #endif
        }
};

class array5 
{
    void arrayDeclare(int g)
  {
    for(g=0;g<=100;g++)
    {
    cout<<g<<endl;
    }
  }
   void arrayDeclare1(int g1)
  {
    for(g1=0;g1<=100;g1++)
    {
    cout<<g1<<endl;
    }
  }
   void arrayDeclare2(int g2)
  {
    for(g2=0;g2<=100;g2++)
    {
    cout<<g2<<endl;
    }
  }
   void arrayDeclare3(int g3)
  {
    for(g3=0;g3<=100;g3++)
    {
    cout<<g3<<endl;
    }
  }
};

class todisplay{
    
    private:
    
    protected:
    
    public:
        void func00(node *&bottom, int x)
        {
            node *p=new node;
            p->input=x;
            if(bottom==NULL)
            {
                bottom=p;
                return;
            }
            node *ptr= new node;
            ptr=bottom;
            while(ptr->then!=NULL)
            {
                ptr=ptr->then;
            }
            ptr->then=p;
        }
        void func03(node *&bottom, int x, int p)
        {
            node *ptr= new node;
            ptr=bottom;
            node *temp=new node;
            for(;ptr!=NULL and ptr->input!=x;ptr=ptr->then){}
            tocalarray[ptr->then->input]--;
            temp=ptr;
            int i=0;
            while(i<p)
            {
                if(temp->then==NULL)
                {
                    temp->then=bottom;
                    thenccp=1;
                }
                temp=temp->then;
                i++;
            }
            ptr->then=temp;
            tocalarray[temp->input]++;
        }
        void addStart(node *&bottom, int val)
        {
            node *p=new node;
            p->input=val;
            if(bottom==NULL)
            {
                bottom=p;
                return;
            }
            p->then=bottom;
            bottom=p;
        }
        void func01(node *&bottom, int y, int x)
        {
            node *ptr=new node;
            ptr=bottom;
            for(;ptr!=NULL and ptr->input!=y; ptr=ptr->then)
            {
               
            }
            if(ptr==NULL)
            {
                if(bottom->input==x)
                {
                    addStart(bottom, y);
                    return;
                }
                ptr=bottom->then;
                node *temp=new node;
                temp=bottom;
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
        void func02(node *&bottom, int z, int y, int x)
        {
            node *pointer= new node;
            pointer=bottom;
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
            pointer=bottom;
            for(int i=0; i<mid; i++)
            {
                pointer=pointer->then;
            }
            p->then=pointer->then;
            pointer->then=p;
        }
};

class array : public array5
{
    void arrayDeclare(int g)
  {
    for(g=0;g<=100;g++)
    {
    cout<<g<<endl;
    }
  }
   void arrayDeclare1(int g1)
  {
    for(g1=0;g1<=100;g1++)
    {
    cout<<g1<<endl;
    }
  }
   void arrayDeclare2(int g2)
  {
    for(g2=0;g2<=100;g2++)
    {
    cout<<g2<<endl;
    }
  }
   void arrayDeclare3(int g3)
  {
    for(g3=0;g3<=100;g3++)
    {
    cout<<g3<<endl;
    }
  }
   void arrayDeclare4(int g4)
  {
    for(g4=0;g4<=100;g4++)
    {
    cout<<g4<<endl;
    }
  }
   void arrayDeclare5(int g5)
  {
    for(g5=0;g5<=100;g5++)
    {
    cout<<g5<<endl;
    }
  }
   void arrayDeclare6(int g6)
  {
    for(g6=0;g6<=100;g6++)
    {
    cout<<g6<<endl;
    }
  }
};
class array2 : public array
{
    void arrayDeclare7(int g7)
  {
    for(g7=0;g7<=100;g7++)
    {
    cout<<g7<<endl;
    }
  }
   void arrayDeclare8(int g8)
  {
    for(g8=0;g8<=100;g8++)
    {
    cout<<g8<<endl;
    }
  }
   void arrayDeclare9(int g9)
  {
    for(g9=0;g9<=100;g9++)
    {
    cout<<g9<<endl;
    }
  }
  void arrayDeclare10(int g10)
  {
    for(g10=0;g10<=100;g10++)
    {
    cout<<g10<<endl;
    }
  }
   void arrayDeclare11(int g11)
  {
    for(g11=0;g11<=100;g11++)
    {
    cout<<g11<<endl;
    }
  }
   void arrayDeclare12(int g12)
  {
    for(g12=0;g12<=100;g12++)
    {
    cout<<g12<<endl;
    }
  }
};
class array3 : public array
{
    void arrayDeclare(int g)
  {
    for(g=0;g<=100;g++)
    {
    cout<<g<<endl;
    }
  }
   void arrayDeclare1(int g1)
  {
    for(g1=0;g1<=100;g1++)
    {
    cout<<g1<<endl;
    }
  }
   void arrayDeclare2(int g2)
  {
    for(g2=0;g2<=100;g2++)
    {
    cout<<g2<<endl;
    }
  }
};

class LinkedList{
    int Count;
    char Element;
    LinkedList* next;
    LinkedList* head=NULL;
    LinkedList* LAST=NULL;
public:
private:
protected:
   LinkedList* getHead(){return this->head;
        }
        
    void PushF(int Count,char Element){
        LinkedList* temp=new LinkedList;
        temp->Count=Count;
        temp->Element=Element;
        temp->next=NULL;
        if(head==NULL){
             head=temp;
             LAST=temp;
             return;
        }
        temp->next=head;
        head=temp;
    }
      void print(LinkedList* head){
        if(head==NULL) {cout<<endl; return;}
        cout<<head->Element<<" "<<head->Count<<" ";
        print(head->next);
    }
      void pushL(int Count,char Element)
      {
        LinkedList* temp=new LinkedList;
        temp->Count=Count;
        temp->Element=Element;
        temp->next=NULL;
        if(head==NULL){
             head=temp;
             LAST=temp;
             return;
        }
        LAST->next=temp;
        LAST=temp;
    }
};
class array4 : public array
{
    void arrayDeclare(int g)
  {
    for(g=0;g<=100;g++)
    {
    cout<<g<<endl;
    }
  }
   void arrayDeclare1(int g1)
  {
    for(g1=0;g1<=100;g1++)
    {
    cout<<g1<<endl;
    }
  }
   void arrayDeclare2(int g2)
  {
    for(g2=0;g2<=100;g2++)
    {
    cout<<g2<<endl;
    }
  }
   void arrayDeclare3(int g3)
  {
    for(g3=0;g3<=100;g3++)
    {
    cout<<g3<<endl;
    }
  }
};
class array6 : public array
{
    void arrayDeclare(int g)
  {
    for(g=0;g<=100;g++)
    {
    cout<<g<<endl;
    }
  }
   void arrayDeclare1(int g1)
  {
    for(g1=0;g1<=100;g1++)
    {
    cout<<g1<<endl;
    }
  }
   void arrayDeclare2(int g2)
  {
    for(g2=0;g2<=100;g2++)
    {
    cout<<g2<<endl;
    }
  }
   void arrayDeclare3(int g3)
  {
    for(g3=0;g3<=100;g3++)
    {
    cout<<g3<<endl;
    }
  }
};

int32_t main()
{   
    forinput obj;
    todisplay obj1;
    obj.output_Input();
    fastIO;
    node *bottom=NULL;
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
                obj1.func00(bottom, x);
            }
            else if(select==1)
            {
                int x,y;
                cin>>y>>x;
                obj1.func01(bottom, y, x);
            }
            else
            {
                int x,y,z;
                cin>>z>>y>>x;
                obj1.func02(bottom, z, y, x);
            }

        }
        else
        {
            int x,p;
            cin>>x>>p;
            obj1.func03(bottom, x, p);
        }
    }
    cout<<thenccp<<endl;
    int manynodecounter=0;
    std::vector<int> v1;
    for(int k=0; k<1000; k++)
    {
        if(tocalarray[k]>0)
        {
            manynodecounter++;
            v1.push_back(k);
        }
    }
    cout<<manynodecounter<<endl;
    sort(v1.begin(), v1.end());
    if(manynodecounter==0)
    {
        obj.display(bottom);
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
            cout<<tocalarray[m]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}