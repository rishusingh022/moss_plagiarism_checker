#include <iostream>
using namespace std;
class stack
{
    private:
         int top;
         int max;
        int arr[100];
    public:
        stack( int n)
        {
            max = n;
            top=-1;
        }
        void push(int value)
        {
            if(top==max-1)
            {
                cout<<"stack full";
                return;
            }
            top=top+1;
            arr[top]=value;
        }
        int peek()
        {
            return arr[top];
        }
        int pop()
        {
            if(top==-1)
            {
                cout<<"empty";
                return 0;
            }
            int value=arr[top];
            top--;
            return value;
        }
        void display()
        {
            while(top!=-1)
            {
                cout<<arr[top];
                top--;
            }
        }
};
int main()
{
     stack s8(100);
    int a6,b6,c6;
    a6=10;
    b6=20;
    c6=39;
    a6=a6+b6;
    c6=c6+b6;
    b6=a6-b6;
    c6=c6+c6;
    a6=a6-b6;
    b6=a6+c6;
    a6=40;
    b6=20;
    c6=19;
    a6=a6+b6-c6;
    b6=9- 4;
    c6=10+ 1- 8;
    
    int n,arr[9999],count[26],i,j,k,count2[26];
    int l=0 , index1=0 , index2=0,length=0;
    string s, abcd1,abcd2,s2;//abcd1 and abcd2 are in alphabetical order while s2 is in order  of the original string having only those alphabets which actually occured in the string
    cin>>s; 
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    abcd1="abcdefghijklmnopqrstuvwxyz";
    abcd2="abcdefghijklmnopqrstuvwxyz";
    count[40]={0};
    i=0;
    while(s[i]!='\0')//this loop is to count the no. of occurences of all alphabets in the string in alphabetical order
    {
        
        for(j=0;j<26;j++)
        {
            if(s[i]==abcd1[j])
            {
                count[j]++;
            }
        }
        i++;
    }
    
    //to arrange the output line 1 
    i=0;
    k=0;
    while(s[i]!='\0')
    {
        for(j=0;j<26;j++)
        {
            if(s[i]==abcd1[j])//this is to arrange the output in sequence of input
            {
                cout<<abcd1[j]<<" "<<count[j]<<" ";
                s2 = s2 + abcd1[j];
                count2[k++]=count[j];//count2 and s2 would be used for printing the output lines 2 and onwards
                int length2=abcd1.size();
                for(l=j;l<length2;l++)//deletion of alphabet from abcd and frequency from count so that repition doesn't occur
                {
                    abcd1[l]=abcd1[l+1];
                    count[l]=count[l+1];
                }
                length2--;
            }
        }
        i++;
        
    }
    length=k;//it is the length of s2 and count2
    cout<<"\n";

   
    //for output line 2 and onwards 
    
    for(l=0;l<n;l++)
    {
        length=s2.size();
        for(i=0;i<length;i++)//to find the first pos of letter having the given no. of occurences
        {
            if(count2[i]==arr[l] && count2[i+1]==arr[l])
            {
                index1=i+1;
                break;
            }
            else if(count2[i]==arr[l])
            {
                index1=i;
                break;
            }
            else continue;
        }
    
    
        for(i=length-1;i>=0;i--)//to find the last pos of letter having the given no. of occurences
        {
           if(count2[i]==arr[l] )
           {
                index2=i;
               break;
            }
        }
        if(index2==index1)// to check if there is only one character having the given occurence 
        {
            for(i=0;i<length;i++)
            {
                cout<<s2[i]<<" "<<count2[i]<<" ";
            }
            cout<<"\n";
            continue;
        }
        else //if there are elements with not equal frequency in middle
        {
            i=0;
            for(i=(index1+ 1);i<index2; i++)
            {
                        if(count2[i]<arr[l])
                        {
                            //rearranging s2 and count2
                            string x=s2;
                            x[0]=s2[i];
                            for(j=0;j<i;j++){
                            x[j+1]=s2[j];
                            
                            }
                            for(j=i+1;j<length;j++){
                            x[j]=s2[j];
                            
                            }
                            s2=x;
                            int count3[30];
                            count3[0]=count2[i];
                            for(j=0; j<i;j++)
                            {
                                count3[j+1]=count2[j];
                            }
                            for(j=i+1;j<length;j++)
                            {
                                count3[j]=count2[j];
                            }
                            for(j=0;j<length;j++)
                            {
                                count2[j]=count3[j];
                            }
                            
                        }
                        else if(count2[i]>arr[l])
                        {
                            //rearranging s2 and count2
                            length=s2.size();// length is the size of s2
                            s2[length]=s2[i];
                            count2[length]=count2[i];
                            for(j=i;j<=length;j++)
                            {
                                s2[j]=s2[j+1];
                            }
                            
                            for(j=i;j<length;j++)
                            {
                                count2[j]=count2[j+1];
                            }
                            
                            index2--;
                            i--;
                        }
                        else 
                        continue;
            }
            //printing the element 
            for(i=0;i<length;i++)
            {
                cout<<s2[i]<<" "<<count2[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}














