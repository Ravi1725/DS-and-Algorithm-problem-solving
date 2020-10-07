//Take as input N, the size of array. Take N more inputs and store that in an array. 
//Take as input M, a number. Write a recursive function which returns an array containing 
//indices of all items in the array which have value equal to M. 
//Print all the values in the returned array.

#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

void count_indices(int *input,int *output,int n,int i,int j,int key)
{
	int count=0;
	//base case
	if(n==0)
	{
		output[j]=1000000;
		return;
	}
	if(input[i]==key)
	{
		cout<<j<<","<<i<<endl;
		output[j]=i;
		count_indices(input,output,n-1,i+1,j+1,key);
	}
	else
	{
		count_indices(input,output,n-1,i+1,j,key);
	}
	//recursive case

}

int main()
{
	int *input;
	int *output;
	int key,n,itr;
	cin>>n;
	input=new int[n];
	output=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>input[i];
	}
	cin>>key;

	cout<<endl;
	count_indices(input,output,n,0,0,key);

	cout<<endl;
	itr=sizeof(output)/sizeof(output[0]);
	cout<<itr<<endl;
	for(int i=0;output[i]!=1000000;i++)
	{
		cout<<output[i]<<" ";
	}
	
	
	return 0;
}