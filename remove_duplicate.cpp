//Take as input S, a string. Write a function that removes all consecutive duplicates. Print the value returned.
//Input - aaaabbcd, aacbbcd
//output - abcd ,  acbcd
#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

void remove_duplicate(char *arr,char *output,int n, int i,int j)
{
	//base case
	if(arr[i]=='\0')
	{
		output[j]='\0';
		//cout<<output<<endl;
		return;
	}
	

	//recursive case
	
	if(arr[i]==arr[i+1])
	{
		//output[j]=arr[i];
		for(int j=i; arr[j]!='\0';j++)
		{
			arr[j+1]=arr[j+2];
		}
		remove_duplicate(arr,output,n-2,i,j);
	}

	
	output[j]=arr[i];
	remove_duplicate(arr,output,n-1,i+1,j+1);


	

}

int main()
{
	char arr[1000];
	char output[1000];
	int n;
	cout<<"Enter the strings"<<endl;
	cin>>arr;
	n=strlen(arr);
	remove_duplicate(arr,output,n,0,0);
	cout<<output<<endl;
		
	return 0;
}