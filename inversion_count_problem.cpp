#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int merge(int *arr, int s,int e)
{
	int mid=(s+e)/2;
	int i=s;
	int j=mid+1;
	int k=s;
	int temp[100000];
	int cnt=0;
	while(i<=mid & j<=e)
	{
		if(arr[i]<=arr[j])
		{
			temp[k]=arr[i];
			k++;
			i++;
		} 
		else
		{
			temp[k++]=arr[j++];
			cnt+=mid-i+1;
		}
	}
	return cnt;
}

int inversion_count(int *arr, int s,int e)
{
	//base case
	if(s>=e)
		return 0;
	int mid=s+(e-s)/2;
	int x=inversion_count(arr,s,mid);
	int y=inversion_count(arr,mid+1,e);
	int z=merge(arr,s,e);
	return x+y+z;
}


int main()
{
	int arr[]={1,5,3,2,0,4};
	int n=sizeof(arr)/sizeof(int);
	cout<<inversion_count(arr,0,n-1)<<endl;
	return 0;
}