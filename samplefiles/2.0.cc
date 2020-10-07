#include<bits/stdc++.h>
using namespace std;
void peek(int arr[][3], int str, int stc, int diff)
{
	int k;
	for(k=1;k<=arr[0][2];k++)
	{
		if(arr[k][0]==str)
		{
			if(arr[k][1]==stc)
			{
				cout<<arr[k][0]<<" "<<arr[k][1]<<" "<<arr[k][2]<<" "<<diff<<endl;
				break;
			}
		}
	}
}
int main()
{
	int n,m,non,stc,str,i,diff,x,k;
	diff=k=1;
	cin>>n;
	cin>>m;
	cin>>non;
	int arr[non+1][3];
	arr[0][0]=n;
	arr[0][1]=m;
	arr[0][2]=non;
	for(i=1;i<=non;i++)
	{
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	cin>>str>>stc;
	peek(arr,str,stc,diff);
	x=1;
	while(x<=(m*n))
	{
		for(i=0;i<k;i++)
		{
			str++;
			x++;
			diff=1;
			peek(arr,str,stc,diff);
		}
		for(i=0;i<k;i++)
		{
			stc++;
			x++;
			diff=2;
			peek(arr,str,stc,diff);
		}
		k++;
		for(i=0;i<k;i++)
		{
			str--;
			x++;
			diff=3;
			peek(arr,str,stc,diff);
		}
		for(i=0;i<k;i++)
		{
			stc--;
			x++;
			diff=4;
			peek(arr,str,stc,diff);
		}
		k++;
	}
	return 0;
}
