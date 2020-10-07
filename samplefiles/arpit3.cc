#include<bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
void inOut()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
}
struct node
{
    int data;
    node *next=NULL;
};
int isCircular=0;
int nextcountarr[1000]={0};
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
    nextcountarr[ptr->next->data]--;
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
    nextcountarr[temp->data]++;
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
class Answer
{
     private:               //Private section starts
          int empid;
          float esalary;
     public:             //Public section starts
          void display()     //Member function
          {
               empid = 001;
               esalary = 10000;
               cout<<"Employee Id is : "<<empid<<endl;
               cout<<"Employee Salary is : "<<esalary<<endl;
          }
          void show1(const int nElements, string texts[]) {

	// cout << sizeof(texts) << endl; returns sizeof pointer!

        for(int i=0; i<nElements; i++) {
        	cout << texts[i] << endl;
        }
        }
        
        void show2(const int nElements, string *texts) {
        
        // cout << sizeof(texts) << endl; returns sizeof pointer!
        
        for(int i=0; i<nElements; i++) {
        	cout << texts[i] << endl;
        }
        }
        
        void show3(string (&texts)[3]) {
        
        // cout << sizeof(texts) << endl; returns sizeof pointer!
        
        for(int i=0; i<sizeof(texts)/sizeof(string); i++) {
        	cout << texts[i] << endl;
        }
        }
        
        char *getMemory() {
        char *pMem = new char[100];
        
        return pMem;
        }
        
        void freeMemory(char *pMem) {
        delete [] pMem;
        }
        // A utility function to check if a string str is palindrome 
        bool isPalindrome(string str) 
        { 
        // Start from leftmost and rightmost corners of str 
        int l = 0; 
        int h = str.length() - 1; 
        
        // Keep comparing characters while they are same 
        while (h > l) 
            if (str[l++] != str[h--]) 
                return false; 
        
        // If we reach here, then all characters were matching 
        return true; 
        } 
        
        // Function to check if a given string is a rotation of a 
        // palindrome. 
        bool isRotationOfPalindrome(string str) 
        { 
        // If string iteself is palindrome 
        if (isPalindrome(str)) 
            return true; 
        
        // Now try all rotations one by one 
        int n = str.length(); 
        for (int i = 0; i < n - 1; i++) { 
            string str1 = str.substr(i + 1, n - i - 1); 
            string str2 = str.substr(0, i + 1); 
        
            // Check if this rotation is palindrome 
            if (isPalindrome(str1.append(str2))) 
                return true; 
        } 
        return false; 
        }
        int fact(int i)
        {
            if(i<0)
            {
                runtime_error err("Input cannot be a negative number");
                cout << err.what() << endl;
            }
            return i > 1 ? i * fact( i - 1 ) : 1;
        }
        bool checkPal(int x, int len) 
    { 
        if (x == len) 
            return true; 
        else if (x > len) { 
            if ((x % 2 == 0 && len % 2 == 0) 
                || (x % 2 != 0 && len % 2 != 0)) 
                return true; 
        } 
        return false; 
    } 
      
    // Function to preprocess the string 
    // for Manacher's Algorithm 
    string reform(string s) 
    { 
        string s1 = "$#"; 
      
        // Adding # between the characters 
        for (int i = 0; i < s.size(); i++) { 
            s1 += s[i]; 
            s1 += '#'; 
        } 
      
        s1 += '@'; 
        return s1; 
    } 
      
    // Function to find the longest palindromic 
    // substring using Manacher's Algorithm 
    bool longestPal(string s, int len) 
    { 
      
        // Current Left Position 
        int mirror = 0; 
      
        // Center Right Position 
        int R = 0; 
      
        // Center Position 
        int C = 0; 
      
        // LPS Length Array 
        int P[s.size()] = { 0 }; 
        int x = 0; 
      
        // Get currentLeftPosition Mirror 
        // for currentRightPosition i 
        for (int i = 1; i < s.size() - 1; i++) { 
            mirror = 2 * C - i; 
      
            // If currentRightPosition i is 
            // within centerRightPosition R 
            if (i < R) 
                P[i] = min((R - i), P[mirror]); 
      
            // Attempt to expand palindrome centered 
            // at currentRightPosition i 
            while (s[i + (1 + P[i])] == s[i - (1 + P[i])]) { 
                P[i]++; 
            } 
      
            // Check for palindrome 
            bool ans = checkPal(P[i], len); 
            if (ans) 
                return true; 
      
            // If palindrome centered at currentRightPosition i 
            // expand beyond centerRightPosition R, 
            // adjust centerPosition C based on expanded palindrome 
            if (i + P[i] > R) { 
                C = i; 
                R = i + P[i]; 
            } 
        } 
      
        return false; 
    } 
};
int32_t main()
{
    inOut();
    fastIO;
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
    cout<<isCircular<<endl;
    int multiNodeCounter=0;
    std::vector<int> v1;
    for(int k=0; k<1000; k++)
    {
        if(nextcountarr[k]>0)
        {
            multiNodeCounter++;
            v1.push_back(k);
        }
    }
    cout<<multiNodeCounter<<endl;
    sort(v1.begin(), v1.end());
    if(multiNodeCounter==0)
    {
        display(head);
    }
    else
    {
        for(auto m : v1)
        {
            cout<<m<<" ";
        }
        cout<<endl;
    }
    if(multiNodeCounter>0)
    {
        for(auto m : v1)
        {
            cout<<nextcountarr[m]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}