#include<iostream>
using namespace std;

void last_index(int arr[],int n,int m,int i,int k)
{
	//base case
	if(n==0)
	{
		cout<<k<<endl;
		return;
	}

	//recursive case
	if(arr[i]==m)
	{
		k=i;
		last_index(arr,n-1,m,i+1,k);
		//cout<<k<<endl;
	}

	last_index(arr,n-1,m,i+1,k);
	
}
int main() {
	int n,*arr;
	int m;
	cin>>n;
	arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>m;
	last_index(arr,n,m,0,-1);
	return 0;
}