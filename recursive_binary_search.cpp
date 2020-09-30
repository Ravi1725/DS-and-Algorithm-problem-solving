#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int rec_binary_search(int arr[],int s, int l,int key)
{
	if(s<=l)
	{
		int mid=s+(l-s)/2;
		//cout<<mid<<key<<" ";
		if(arr[mid]==key)
		{
			return mid;
		}
		if(arr[mid]>key)
		{
			rec_binary_search(arr,s,mid-1,key);
		}
		rec_binary_search(arr, mid+1,l,key);	
	}
	return -1;
}

int main()
{
	int arr[]={8,9,14,17,90,100};
	int key=8;
	int key1=101;
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<rec_binary_search(arr,0,n-1,key);
	return 0;
}