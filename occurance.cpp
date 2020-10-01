#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int first_occurance(int *arr, int n,int key)
{
	if(n==0)
		return -1;
	if(arr[0]==key)
		return 0;
	int i=first_occurance(arr+1,n-1,key);
	if(i==-1)
	{
		return -1;
	}
	else
		return i+1;
}

int last_occurance(int *arr,int n,int key)
{
	if(n==0)
		return -1;
	int i=last_occurance(arr+1,n-1,key);
	if(i==-1)
	{
		if(arr[0]==key)
			return 0;
		else
			return -1;
	}
	return i+1;
}

int main()
{
	int arr[]={3,4,5,3,6,7,1,7};
	int n=sizeof(arr)/sizeof(int);
	cout<<first_occurance(arr,n,7)<<endl;
	cout<<last_occurance(arr,n,7)<<endl;
	return 0;
}