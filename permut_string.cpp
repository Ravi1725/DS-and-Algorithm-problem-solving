//Recursion with backtracking problem.
//this program will give all permuted strings from given input string. 
#include<iostream>
#include<set>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

void permut(string arr, int i,set<string> &s)
{
	//base case
	if(arr[i]=='\0')
	{
		//This will print with redudant solution
		cout<<arr<<",";
		s.insert(arr);
		return;
	}

	//recursive case
	for (int j=i;arr[j]!='\0';j++)
	{
		swap(arr[i],arr[j]);
		permut(arr,i+1,s);
		swap(arr[i],arr[j]);
	}
}

int main()
{
	string arr;
	cout<<"Enter the string, you want to permut"<<endl;
	cin>>arr;
	set<string> s;
	permut(arr,0,s);

	cout<<endl;

	//this will print result excluding all redundancy of permuted string.
	for(auto str : s)
	{
		cout<<str<<" , ";
	}
	return 0;
}