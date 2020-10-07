#include <iostream>
using namespace std;

class school{
public:
    int n;
    struct node{
int data;
node *next;
node *prev;
};
node *head=NULL;
void InsertBeg(int a){
node *temp=new node;
temp->data=a;
temp->next=head;
head=temp;
}
void display(){
node *temp=head;
while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;
}


}
void InsertEnd(int a){
node *temp=new node;
temp->next=NULL;
temp->data=a;
if(head==NULL){
    head=temp;
}
else{
    node *temp1=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=temp;
}
}
void Insert(int a,int x){
    node *temp=new node;
    temp->data=a;
    temp->next=NULL;
    node *temp1=head;
    while(temp1 && temp1->data!=x)
    {
        temp1=temp1->next;
    }
    if(temp1=NULL){
        cout<<"Element not found,so can't insert"<<endl;
        delete temp;
    }
    else{
        temp->next=temp1->next;
        temp1->next=temp;
    }
}
void deletehead(){
if(head==NULL){
    cout<<"list is empty"<<endl;
}
else{
    node *temp=head;
    head=head->next;
    delete temp;
}
}
void occu(int x){
node *temp=head;
int count =0;
while(temp!=NULL){
    if(temp->data==x){
        count++;
    }
    temp=temp->next;
}
cout<<"The key occurs "<<count<<" times"<<endl;
}

void deleteoccu(int x){
node *current=head;
node *temp=NULL;
node *next=NULL;
while(current!=NULL){
    temp=current;
    next=current->next;
    if(current->data==x){
        while(next!=NULL){
            if(next->data==current->data){
                temp->next=next->next;
            }
            else{
                temp=next;
            }
         next=next->next;
        }
    }
    current=current->next;
}
}
void middle(){
node *mid=head;
int count=0;
while(head!=NULL){
    if((count%2)!=0){
        mid=mid->next;
    }
    count++;
    head=head->next;
}
if(mid!=NULL){
    cout<<"The middle element is "<<mid->data;
}
else{
    cout<<"the list is empty"<<endl;
}
}
void reverselist(node *head){
if(head==NULL)
    return;
else
    reverselist(head->next);
cout<<head->data<<endl;
}



void deletespecific(int a){
if(head==NULL){
    cout<<"Empty"<<endl;
}
else{
    node *temp=head,*pre;
    while(temp->next!=head && temp->data!=a){
        pre=temp;
        temp=temp->next;
    }
    if(temp==head){
        deletehead();
    }
    else if(temp->data!=a){
        cout<<"Not found"<<endl;
    }
    else{
        pre->next=temp->next;
        delete temp;
    }
}
}
void deleteEnd(){
if(head==NULL){
    cout<<"list is empty"<<endl;
}
else{
    node *temp=head;
    node *pre=NULL;
    while(temp->next!=NULL){
        pre=temp;
        temp=temp->next;
    }
    if(temp==head){
        head==NULL;
    }
    else{
        pre->next=NULL;
    }
    delete temp;
}
}
void deletenode(int a){
if(head==NULL)
    cout<<"empty list"<<endl;
else{
    node *temp=head,*pre=NULL;
    while(temp && temp->data!=a){
        pre=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"element not found"<<endl;
    }
    else{
        if(temp==head)
            head=head->next;
        else
            pre->next=temp->next;
        delete temp;
    }
    }
}
void insert(int x, int y){
    if(head==NULL){
        cout<<"list is empty"<<endl;
    }
    else{
        node *temp1=head;
        while(temp1!=NULL && temp1->data!=y){
            temp1=temp1->next;
        }
        if(temp1==NULL){
            cout<<"element not found"<<endl;
        }
        else{
           node *temp=new node;
           temp->data=x;
           temp->next=temp1->next;
           temp->prev=temp1;
           temp1->next=temp;
           temp->next->prev=temp;
        }
    }

}

};
bool equal(int temp, int l, int k)
{
    if(k==0 || k==1)
        return temp<=l;
    else
        return temp<l;
}

int main()
{
    int sparse[3];
    for (int i = 0; i < 3; i++){
        cin >> sparse[i];
    }
    int s[sparse[2]][3];
    for (int i = 0; i < sparse[2]; i++){
        for (int j = 0; j < 3; j++){
            cin >> s[i][j];
        }
    }
    int initial_indices[2];
    for (int i = 0; i < 2; i++){
        cin >> initial_indices[i];
    }
    int sm[sparse[0]][sparse[1]];
    int k = 0;
    for (int i = 0; i < sparse[0]; i++)
    {
        for (int j = 0; j < sparse[1]; j++)
        {
            if ((j == s[k][1]) && (i == s[k][0]))
            {
                sm[i][j] = s[k][2];
                k=k+1;
            }
            else
            {
                sm[i][j] = 0;
            }
        }
    }
    int answer[sparse[2]][4];
    k = 0;
    int l = 1;
    char dir='d';
    int a = -1;
    int t = 0;
    while(k<sparse[0]*sparse[1])
    {
        while(equal(t, l, k))
        {
            if(sm[initial_indices[0]][initial_indices[1]]!=0)
            {
                a=a+1;
                answer[a][0] = initial_indices[0];
                answer[a][1] = initial_indices[1];
                answer[a][2] = sm[initial_indices[0]][initial_indices[1]];
                if(dir=='d'){
                    answer[a][3]=1;
                }
                else{
                    answer[a][3]=3;
                }
            }
            if((k==0 && t!=l) || (k!=1 && t!=l-1))
            {
                if(dir=='d')
                {
                    initial_indices[0]++;
                }
                else if(dir=='u')
                {
                    initial_indices[0]--;
                }
            }
            t=t+1;
            k=k+1;
        }
        t = 0;
        if(dir=='u')
        {
            dir='l';
            initial_indices[1]--;
        }
        else if(dir=='d')
        {
            dir='r';
            initial_indices[1]++;
        }
        if(k>=sparse[0]*sparse[1])
            break;
        while(t<l)
        {
            if(sm[initial_indices[0]][initial_indices[1]]!=0)
            {
                a++;
                answer[a][0] = initial_indices[0];
                answer[a][1] = initial_indices[1];
                answer[a][2] = sm[initial_indices[0]][initial_indices[1]];
                answer[a][3] = ((dir=='r') ? (2) : (4));
            }
            if(t!=l-1)
            {
                if(dir=='l')
                {
                    initial_indices[1]--;
                }
                else if(dir=='r')
                {
                    initial_indices[1]++;
                }
            }
            t=t+1;
            k=k+1;
        }
        t = 0;
        if(dir=='l')
        {
            dir='d';
            initial_indices[0]++;
        }
        else if(dir=='r')
        {
            dir='u';
            initial_indices[0]--;
        }
        l=l+1;
    }
    for(int i=0; i<sparse[2]; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
}


