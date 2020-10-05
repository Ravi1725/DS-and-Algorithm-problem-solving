//Recursive problem
//It will print all possible parenthesis set bygiven number.
#include<iostream>
#include<set>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

void parenthesis(char *arr,int n,int i, int open,int close)
{
	//base case
	if(i==2*n)
	{
		arr[i]='\0';
		cout<<arr<<endl;
		return;
	}

	//recursive case
	if(open<n)
	{
		arr[i]='(';
		parenthesis(arr,n,i+1,open+1,close);
	}
	if(close<open)
	{
		arr[i]=')';
		parenthesis(arr,n,i+1,open,close+1);
	}

	return;

}
int main()
{
	char arr[100];
	int n;
	cout<<"Enter the value of n"<<endl;
	cin>>n;
	parenthesis(arr,n,0,0,0);
	return 0;
}