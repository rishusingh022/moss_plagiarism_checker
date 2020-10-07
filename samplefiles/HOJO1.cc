#include <iostream>
using namespace std;

class LinkedList {
    int data;
    LinkedList *next;
    LinkedList *head = NULL;
    int* freq = new int[1500];
    //ARRAY FOR STORING THE NUMBER OF
    //NODES POINTING TO A NODE
    LinkedList* nv[1500];
    //ARRAY FOR STORING THE NUMBER OF
    //NODES BY WHICH A NODE IS BEING POINTED AT
public:
    int nE = 0;
    bool flag = false;
    int* getTable() {
        return freq;
    }
    LinkedList()
    {
        //INITIALIZING THE ARRAYS
        int j=0;
        while(j<1500)
        {
            freq[j]=0;
            nv[j]=NULL;
            j++;
        }
    }
    //FUNCTIONS
    void I0X()
    {
        int X;
        cin>>X;
        LinkedList *temp = new LinkedList;
        temp->data = X;
        temp->next = NULL;
        nv[X] = temp;
        nE+=1;
        //IF THE LIST IS EMPTY
        if (head == NULL) {
            head = temp;
            freq[head->data] = 0;
            return;
        }
        //IF THE LIST IS HAVING SOME VALUES
        LinkedList *temp1 = head;
        while(temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
    void I1XY()
    {
        int X, Y;
        cin>>X>>Y;
        nE+=1;
        if(Search(X))
            insertAfter(X, Y);
        else
            insertBefore(X,Y);
    }
    void insertBefore(int Y, int X)
    {
        LinkedList *temp = new LinkedList;
        temp->data = Y;
        temp->next = NULL;
        nv[Y] = temp;
        if (head->data == X)
        {
            temp->next = head;
            head = temp;
            return;
        }
        LinkedList *temp2 = head;
        while(temp2->next->data != X)
            temp2 = temp2->next;
        temp->next = temp2->next;
        temp2->next = temp;
    }
    void insertAfter(int Y, int X)
    {
        LinkedList *temp = new LinkedList;
        temp->data = X;
        temp->next = NULL;
        nv[X] = temp;
        LinkedList *temp2 = head;
        while(temp2->data != Y)
            temp2 = temp2->next;
        temp->next = temp2->next;
        temp2->next = temp;
    }
    void I2ZYX()
    {
        int X, Y, Z;
        cin>>X>>Y>>Z;
        LinkedList *temp = new LinkedList;
        temp->data = Z;
        temp->next = NULL;
        nv[Z] = temp;
        int num = 0;
        LinkedList *temp1 = head;
        while(temp1->data != X)
            temp1 = temp1->next;
        LinkedList *prev = temp1;
        while (temp1->data != Y)
        {
            temp1 = temp1->next;
            num++;
        }
        num=num/2;
        while (num != 0)
        {
            prev = prev->next;
            num=num-1;
        }
        temp->next = prev->next;
        prev->next = temp;
        nE+=1;
    }
    //FUNCTION TO SEARCH FOR A GIVEN NODE VALUE
    int Search(int x)
    {
        LinkedList *temp = head;
        while (temp != NULL)
        {
            if(temp->data == x)
                return 1;
            temp=temp->next;
        }
        if (temp == NULL) return 0;
    }
    void UXP(int X)
    {
        int P;
        cin>>P;
        if(Search(X)==0)
            return;
        LinkedList *temp = nv[X];
        while (P!=0)
        {
            if (temp->next == NULL)
            {
                temp->next = head;
            temp = head;
            flag = true;
            P--;
            }
            else
            {
                temp = temp->next;
                P--;
            }
        }
        nv[X]->next = temp;
    }
    void printElements();
    void genTable();
    void printTable();
};

//PRINTING ELEMENTS IF THE SECOND LINE OF
//OUTPUT IS 0
void LinkedList::printElements()
{
    LinkedList *temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void LinkedList::genTable()
{
    int j=1;
    while (j < 1500)
    {
        if(nv[j]!=NULL)
        {
            if(nv[j]->next!=NULL)
                freq[nv[j]->next->data]++;
        }
        j++;
    }
}
void LinkedList::printTable()
{
    for(int j=1;j<15;j++)
    {
        cout <<j<<" "<<freq[j]<<endl;
    }
}


int main()
{
    int nop, b, n=0, mul_add, i=1;
    char a;
    cin>>nop;
    LinkedList list;
    while(n<nop)
    {
        cin>>a;
        cin>>b;
        //CHECKING a's VALUE
        if(a=='I')
        {
            if(b==0)
                list.I0X();
            else if (b==1)
                list.I1XY();
            else if (b==2)
                list.I2ZYX();
        }
        else
            continue;
        //CHECKING FOR U
        if(a=='U')
            list.UXP(b);
        n++;
    }
    list.genTable();
    int* ansT = list.getTable();
    if(list.flag)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    //iterating through the loop
    while (i <1500)
    {
        if(ansT[i]>=2)
            mul_add++;
        i++;
    }
    if(mul_add==0)
    {
        cout<<"0"<<endl;
        list.printElements();
    }
    else
    {
        cout<<mul_add<<endl;
        i=1;
        while (i < 1500){
            if (ansT[i]>=2)
                cout<<i<<" ";
                i++;
        }
        cout<<endl;
        int j=1;
        while (j < 1500) {
            if (ansT[j]>=2)
                cout<<ansT[j]<<" ";
            j++;
        }
    }
    cout << endl;
    return 0;
}
