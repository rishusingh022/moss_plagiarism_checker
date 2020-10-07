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
class Node 
{ 
    public:
    int data; 
    Node* next; 
};
int tocrc=0;
int thencountarr[1000]={0};
class solution{
    
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
        
        void input_Output()
        {
            #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
            #endif
        }
};
class cornercases {
    private:
    
    protected:
    
    public:
        void cornercase1()
        {
            int no_of_testcases;
            cin>>no_of_testcases;
            string s[1000];
            int a=0;
            int b=7;
            for(int i=0;i<no_of_testcases;i++){
                //the floor from which lift is called
                int n;
                cin>>n;
                if((abs(a-n))>(abs(b-n))){
                    s[i]='B';
                    b=n;
                    
                }
                else if((abs(a-n))<(abs(b-n))){
                    s[i]='A';
                    a=n;
                }
                else{
                    if(a>b){
                        s[i]='B';
                        b=n;
                    }
                    else{
                        s[i]='A';
                        a=n;
                    }
                }
                //else if((abs(*pa-n))==(abs(*pb-n))){
                //    
                //    
                //}
                
            }
            for(int j=0;s[j]!="\0";j++){
                cout<<s[j]<<"\n";
            }
        }
        void cornercase2(){
            int count=0;
            int num_testcases;
            cin>>num_testcases;
            int a[num_testcases];
            int t=num_testcases;
            while(t>0){
                int cost_of_green;
                int cost_of_purple;
                cin>>cost_of_green;
                cin>>cost_of_purple;
                int i=0;
                int j=0;
                int sum1=0;
                int sum2=0;
                //now how many participant we want 
                int no_of_participant;
                cin>>no_of_participant;
                int arr[10][2]={0};
                //to take input of no_of_participant
                for(i=0;i<no_of_participant;i++){
                    for( j=0;j<2;j++){
                        cin>>arr[i][j];
                        if(j==0){
                            sum1=sum1+arr[i][j];
                        }
                        else{
                            sum2=sum2+arr[i][j];
                        }
                    }
                }
                int min=0;
                int max=0;
                if(cost_of_green<cost_of_purple){
                    min=cost_of_green;
                    max=cost_of_purple;
                }
                else{
                    min=cost_of_purple;
                    max=cost_of_green;
                }
                int c;
                if(sum1>sum2){
                    c=(sum1*min)+(sum2*max);
                }
                else{
                    c=(sum2*min)+(sum1*max);
                }
                int d=num_testcases-t;
                a[d]=c;
                t--;
                
            }
            for(int k=0;k<num_testcases;k++){
                cout<<a[k]<<endl;
            }
        }
        void testcaseerror_4(Node* head) 
        { 
            Node* current = head; 
         
            Node* next_next; 
             
            /* do nothing if the list is empty */
            if (current == NULL) 
            return; 
         
            while (current->next != NULL) 
            { 
            if (current->data == current->next->data) 
            { 
                next_next = current->next->next; 
                free(current->next); 
                current->next = next_next; 
            } 
            else
            { 
                current = current->next; 
            } 
            } 
        }
        int cornercase3(){
            int arr[100000];
            int a[100000];
            int facing_num[100000];
            int num_testcases;
            cin>>num_testcases;
            for(int i=0;i<num_testcases;i++){
                cin>>arr[i];
            }
            for(int j=0;j<num_testcases;j++){
                int num=arr[j];
                if(num<=12){
                    facing_num[j]=abs(13-num);
                    a[j]=abs(facing_num[j]-num);
                }    
                else if((num>=13)&&(num<=24)){
                    facing_num[j]=abs(37-num);
                    a[j]=abs(facing_num[j]-num);
                }    
                else if((num>=97&&num<=108)){
                    facing_num[j]=abs(205-num);
                    a[j]=abs(facing_num[j]-num);
                }    
                
            }
        }
        void count_errors(){
            string s;
            getline(cin,s);
            int count1=0;
            int count2=0;
            int len=s.length();
            for(int i=0;i<len;i++){
                char ch=s[i];
                if(ch=='L'||ch=='R'||ch=='U'||ch=='D'){
                    if(ch=='R'){
                        count1++;
                    }
                    else if(ch=='L'){
                        count1--;
                    }
                    else if(ch=='U'){
                        count2++;
                    }
                    else{
                        count2--;
                    }
                }
            }
            cout<<count1<<" "<<count2;
        }
        void removeDuplicates(Node* head) 
        { 
            Node* current = head; 
         
            Node* next_next; 
             
            /* do nothing if the list is empty */
            if (current == NULL) 
            return; 
         
            while (current->next != NULL) 
            { 
            if (current->data == current->next->data) 
            { 
                next_next = current->next->next; 
                free(current->next); 
                current->next = next_next; 
            } 
            else
            { 
                current = current->next; 
            } 
            } 
        } 
        void push(Node** head_ref, int new_data) 
        { 
            Node* new_node = new Node();
                     
            new_node->data = new_data; 
                         
            new_node->next = (*head_ref);     
            (*head_ref) = new_node; 
        } 
         
        void printList(Node *node) 
        { 
            while (node!=NULL) 
            { 
                cout<<" "<<node->data; 
                node = node->next; 
            } 
        } 
};
int32_t main()
{   solution obj;
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
                obj.function0(top, x);
            }
            else if(select==1)
            {
                int x,y;
                cin>>y>>x;
                obj.function1(top, y, x);
            }
            else
            {
                int x,y,z;
                cin>>z>>y>>x;
                obj.function2(top, z, y, x);
            }

        }
        else
        {
            int x,p;
            cin>>x>>p;
            obj.function3(top, x, p);
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