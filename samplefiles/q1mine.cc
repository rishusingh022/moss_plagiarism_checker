#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//structure  of character and frequency
struct node
{
	int arr_freq;
	char ch;
	node *next;
};
class functions {
    public:
    void show(node **start)
    {
    	cout<<endl;
    	node *x=*start;
    	for(;x!=NULL;x=x->next)
    	{
    		cout<<x->ch<<" "<<x->arr_freq<<" ";
    		
    	}
    }
    void in_order_of_sequence(node **start, int frequency_comp)
    {
    	node *temp1=*start;
    	for(;temp1!=NULL && temp1->arr_freq!=frequency_comp;temp1=temp1->next){}
    	node *last=*start;
    	while(last->next!=NULL)
    	{
    		last=last->next;
    	}
    	if(temp1==NULL)
    	{
    		show(start);
    		return;
    	}
    	node *s=temp1->next;
    	node *temp2=NULL;
    	while(s!=NULL)
    	{
    		if(s->arr_freq==frequency_comp)
    		{
    			temp2=s;
    		}
    		s=s->next;
    	}
    	if(temp2==NULL)
    	{
    		show(start);
    		return;
    	}
    	if(temp2==temp1->next)
    	{
    		show(start);
    		return;
    	}
    	node *t=temp1->next;
    	while(t!=temp2)
    	{
    		if(t->arr_freq!=temp1->arr_freq)
    		{
    			if(t->arr_freq < temp1->arr_freq)
    			{
    				node *s=t->next;
    				temp1->next=s;
    				t->next=*start;
    				*start=t;
    				t=s;
    			}
    			else if(t->arr_freq > temp1->arr_freq)
    			{
    				node *s=t->next;
    				temp1->next=s;
    				last->next=t;
    				t->next=NULL;
    				last=t;
    				t=s;
    			}
    		}
    		else
    		{
    			temp1=t;
    			t=t->next;
    		}
    	}
    	show(start);
    }
    void print_Freq(const std::string&s2,int k, int freq[])
    {
        int i=0;
    	while(i<k)
    	{
    		cout<<s2[i]<<" "<<freq[i]<<" ";
    		i++;
    	}
    }
    void insert_Element(node **start,char b, int a)
    {
    	node *temp=new node();
    	temp->arr_freq=a;
    	temp->ch=b;
    	temp->next=NULL;
    	if(*start==NULL)
    	{
    		*start=temp;
    	}
    	else
    	{
    		node *temp1=*start;
    		for(;temp1->next!=NULL;temp1=temp1->next){}
    		temp1->next=temp;
    	}
    }
};
struct node1
{
    int input;
    node1 *then=NULL;
};
int tocrc=0;
int thencountarr[1000]={0};
class output{
    
    private:
    
    protected:
    
    public:
        void to_print(node1 *top)
        {
            for(node1 *ptr=top;ptr!=NULL;ptr=ptr->then)
            {
               cout<<ptr->input<<" ";
            }
            cout<<endl;
        }
        void function0(node1 *&top, int x)
        {
            node1 *p=new node1;
            p->input=x;
            if(top==NULL)
            {
                top=p;
                return;
            }
            node1 *ptr= new node1;
            ptr=top;
            while(ptr->then!=NULL)
            {
                ptr=ptr->then;
            }
            ptr->then=p;
        }
        void function3(node1 *&top, int x, int p)
        {
            node1 *ptr= new node1;
            ptr=top;
            node1 *temp=new node1;
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
        void insertBeg(node1 *&top, int val)
        {
            node1 *p=new node1;
            p->input=val;
            if(top==NULL)
            {
                top=p;
                return;
            }
            p->then=top;
            top=p;
        }
        void function1(node1 *&top, int y, int x)
        {
            node1 *ptr=new node1;
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
                node1 *temp=new node1;
                temp=top;
                while(ptr!=NULL and ptr->input!=x)
                {
                    ptr=ptr->then;
                    temp=temp->then;
                }
                node1 *p=new node1;
                p->input=y;
                temp->then=p;
                p->then=ptr;
            }
            else
            {
                node1 *p=new node1;
                p->input=x;
                p->then=ptr->then;
                ptr->then=p;
            }
        }
        void function2(node1 *&top, int z, int y, int x)
        {
            node1 *pointer= new node1;
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
            node1 *p=new node1;
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
class Node { 
public: 
    int data; 
    Node* next; 
    int get(Node* head1, Node* head2) 
    { 
        int c1 = getCount(head1); 
        int c2 = getCount(head2); 
        int d; 
      
        // If first is greater 
        if (c1 > c2) { 
            d = c1 - c2; 
            return _get(d, head1, head2); 
        } 
        else { 
            d = c2 - c1; 
            return _get(d, head2, head1); 
        } 
    }
    int _get(int d, Node* head1, Node* head2) 
    { 
        // Stand at the starting of the bigger list 
        Node* current1 = head1; 
        Node* current2 = head2; 
      
        // Move the pointer forward 
        for (int i = 0; i < d; i++) { 
            if (current1 == NULL) { 
                return -1; 
            } 
            current1 = current1->next; 
        } 
        while (current1 != NULL && current2 != NULL) { 
            if (current1 == current2) 
                return current1->data; 
            current1 = current1->next; 
            current2 = current2->next; 
        } 
      
        return -1; 
    } 
    int getCount(Node* head) 
    { 
    Node* current = head; 
    int count = 0; 
    while (current != NULL) { 
        count++; 
        current = current->next; 
    } 
    
    return count; 
    }
    void Alt(Node *head)  
    {  
        if (head == NULL)  
            return;  
        Node *prev = head;  
        Node *node = head->next;  
      
        while (prev != NULL && node != NULL)  
        {  
            prev->next = node->next;  
            free(node);  
            prev = prev->next;  
            if (prev != NULL)  
                node = prev->next;  
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
        while (node != NULL)  
        {  
            cout<< node->data<<" ";  
            node = node->next;  
        }  
    }     
      
}; 
int main()
{
    functions obj;
	node *start=NULL;
	
	string str;
	getline(cin,str);
	
	int i,j,k=0;
	
	int n;
	cin>>n;
	
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int length=str.length();
	//frequency array creation and initialisation to 1
	int char_freq[length];
	i=0;
	while(i<length)
	{
		char_freq[i]=1;
		i++;
	}
	
	
	string str1=str;
	//loop to calculate the frequency of the chararter in the string
	i=0;
	while(i<length)
	{
		for(j=i+1;j<length;j++)
		{
			if(str[i]==str1[j])
			{
				char_freq[k]=char_freq[k]+1;
				str1[j]='0';
			}
		}
		if(str1[i]!='0')
		{
			k=k+1;
		}
		i++;
	}
	int t=0;
	string str2;
	for(i=0;i<length;i++)
	{
		if(str1[i]!='0')
		{
			str2[t]=str1[i];
			t++;
		}
	}
	cout<<str2;
	obj.print_Freq(str2,k,char_freq);
	for(i=0;i<k;i++)
	{
		obj.insert_Element(&start,str2[i],char_freq[i]);
	}
	i=0;
	while(i<n)
	{
		int m=arr[i];
		obj.in_order_of_sequence(&start,m);
		i++;
	}
}