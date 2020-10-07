#include<bits/stdc++.h>
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
void insertend(int a){
node *temp=new node;
temp->data=a;
temp->next=temp->prev=NULL;
if(head==NULL){
    head=temp;
}
else {
        node *temp1=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=temp;
    temp->prev=temp1;
}
}
void search(int x){
if(head==NULL){
    cout<<"Empty list"<<endl;
}
else{
    node *temp=head;
    while(temp->next!=head && temp->data!=x){
        temp=temp->next;
    }
    if(temp->data==x){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}
}
void push(int x){
node *temp=new node;
temp->data=x;
temp->next=head;
head=temp;
}

bool isEmpty(){
 if(head==NULL){
    return true;
 }
 else{
    return false;
 }
}

void pop(){
if(isEmpty()){
    cout<<"underflow"<<endl;
}
else{
    node *temp=head;
    head=head->next;
    delete temp;
}
}



void peek(){
if(!isEmpty()){
    cout<<head->data<<endl;
}
}
void readSparse(int b[][3]){
cout<<"enter the number of rows for sparse matrix"<<endl;
cin>>b[0][0];
cout<<"enter the number of columns"<<endl;
cin>>b[0][1];
cout<<"enter the total number of non zero elements"<<endl;
cin>>b[0][2];
for(int i=1; i<=b[0][2]; i++){
  cin>>b[i][0]>>b[i][1]>>b[i][2];
}
}
void printSparse(int b[][3]){
    int n=b[0][2];
    int flag=0;
for(int i=0; i<b[0][0]; i++){
    for(int j=0; j<b[0][1]; j++){
        for(int k=1; k<=n; k++){
            if(b[k][0]==i && b[k][1]==j){
                cout<<b[k][2];
            }
                else{
                cout<<"0";
            }

        }

    }
    cout<<endl;
}
}
void transpose(int a[][3],int b[][3]){
b[0][0]=a[0][1];
b[0][1]=a[0][0];
b[0][2]=a[0][2];
int k=1;
int n=a[0][2];
if(b[0][2]>0)
for(int i=0; i<a[0][1]; i++){
    for(int j=1; j<=n; j++){
        if(a[j][1]==i){
            b[k][0]=a[j][1];
            b[k][1]=a[j][0];
            b[k][2]=a[j][2];
            k++;
        }
    }
}
}
int add(int sp1[][3], int sp2[][3], int sp3[][3])
{   int k1, k2, k3, tot1, tot2;
    if(sp1[0][0] == sp2[0][0] && sp1[0][1] == sp2[0][1])
    {    tot1 = sp1[0][2]; tot2 = sp2[0][2];
         k1 = k2 = k3 = 1;
         while ( k1 <= tot1 && k2 <= tot2)
         {    if ( sp1[k1][0] < sp2[k2][0] )
              {    sp3[k3][0] = sp1[k1][0];
                   sp3[k3][1] = sp1[k1][1];
                   sp3[k3][2] = sp1[k1][2];
                   k3++; k1++;
              }
              else if ( sp1[k1][0] > sp2[k2][0] )
              {    sp3[k3][0] = sp2[k2][0];
                   sp3[k3][1] = sp2[k2][1];
                   sp3[k3][2] = sp2[k2][2];
                   k3++; k2++;
              }
              else
              {    if ( sp1[k1][1] < sp2[k2][1] )
                   {    sp3[k3][0] = sp1[k1][0];
                        sp3[k3][1] = sp1[k1][1];
                        sp3[k3][2] = sp1[k1][2];
                        k3++; k1++;
                   }
                   else if ( sp1[k1][1] > sp2[k2][1] )
                   {    sp3[k3][0] = sp2[k2][0];
                        sp3[k3][1] = sp2[k2][1];
                        sp3[k3][2] = sp2[k2][2];
                        k3++; k2++;
                   }
                   else
                   {    sp3[k3][0] = sp2[k2][0];
                        sp3[k3][1] = sp2[k2][1];
                        sp3[k3][2] = sp1[k1][2] + sp2[k2][2];
                        k3++; k2++; k1++;
                   }
              }
         }
         while ( k1 <=tot1 )
         {    sp3[k3][0] = sp1[k1][0];
              sp3[k3][1] = sp1[k1][1];
              sp3[k3][2] = sp1[k1][2];
              k3++; k1++;
         }
         while ( k2 <= tot2 )
         {    sp3[k3][0] = sp2[k2][0];
              sp3[k3][1] = sp2[k2][1];
              sp3[k3][2] = sp2[k2][2];
              k3++; k2++;
         }
         sp3[0][0] = sp1[0][0];
         sp3[0][1] = sp1[0][1];
         sp3[0][2] = k3-1;
    }
    else
         printf("\nInvalid Dimensions.\n");
}
};
struct node
{
    int data;
    node *next=NULL;
};

int nca[1000]={0};
int isCircular=0;

void insertBeg(node *&head, int val)
{
    node *p=new node;
    p->data=val;
    if(head==NULL)
    {
        head=p;
        return;
    }
    p->next=head;
    head=p;
}
void I0x(node *&head, int x)
{
    node *p=new node;
    p->data=x;
    if(head==NULL)
    {
        head=p;
        return;
    }
    node *ptr= new node;
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=p;
}
void I1yx(node *&head, int y, int x)
{
    node *ptr=new node;
    ptr=head;
    while(ptr!=NULL and ptr->data!=y)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        if(head->data==x)
        {
            insertBeg(head, y);
            return;
        }
        ptr=head->next;
        node *temp=new node;
        temp=head;
        while(ptr!=NULL and ptr->data!=x)
        {
            ptr=ptr->next;
            temp=temp->next;
        }
        node *p=new node;
        p->data=y;
        temp->next=p;
        p->next=ptr;
    }
    else
    {
        node *p=new node;
        p->data=x;
        p->next=ptr->next;
        ptr->next=p;
    }
}
void I2zyx(node *&head, int z, int y, int x)
{
    node *ptr= new node;
    ptr=head;
    int counter=0;
    int beg=0, end=0;
    while(ptr!=NULL and ptr->data!=z)
    {
        ptr=ptr->next;
        counter++;
    }
    beg=counter;
    while(ptr!=NULL and ptr->data!=y)
    {
        ptr=ptr->next;
        counter++;
    }
    end=counter;
    node *p=new node;
    p->data=x;
    int mid=(beg+end)/2;
    ptr=head;
    for(int i=0; i<mid; i++)
    {
        ptr=ptr->next;
    }
    p->next=ptr->next;
    ptr->next=p;
}
void Uxp(node *&head, int x, int p)
{
    node *ptr= new node;
    ptr=head;
    node *temp=new node;
    while(ptr!=NULL and ptr->data!=x)
    {
        ptr=ptr->next;
    }
    if(ptr->next) nca[ptr->next->data]--;
    temp=ptr;
    for(int i=0; i<p; i++)
    {
        if(temp->next==NULL)
        {
            temp->next=head;
            isCircular=1;
        }
        temp=temp->next;
    }
    ptr->next=temp;
    nca[temp->data]++;
}
void display(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
void sort(int a[], int s)
{
    int temp;
    for(int i=0; i<s; i++)
    {
        for(int j=0; j<s-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    node *head=NULL;
    int n;
    cin>>n;
    while(n--)
    {
        char operation;
        cin>>operation;
        if(operation=='I')
        {
            int option;
            cin>>option;
            if(option==0)
            {
                int x;
                cin>>x;
                I0x(head, x);
            }
            else if(option==1)
            {
                int x,y;
                cin>>y>>x;
                I1yx(head, y, x);
            }
            else
            {
                int x,y,z;
                cin>>z>>y>>x;
                I2zyx(head, z, y, x);
            }

        }
        else
        {
            int x,p;
            cin>>x>>p;
            Uxp(head, x, p);
        }
    }
    if(head==NULL) return 0;
    cout<<isCircular<<endl;
    int countmulti=0;
    int an[1000];
    int i=0;
    for(int k=0; k<1000; k++)
    {
        if(nca[k]>0)
        {
            countmulti++;
            an[i]=k;
            i++;
        }
    }
    cout<<countmulti<<endl;
    sort(an, i);
    if(countmulti==0)
    {
        display(head);
    }
    else
    {
        for(int a=0; a<i; a++)
        {
            cout<<an[a]<<" ";
        }
        cout<<endl;
    }
    if(countmulti>0)
    {
        for(int a=0; a<i; a++)
        {
            cout<<nca[an[a]]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
