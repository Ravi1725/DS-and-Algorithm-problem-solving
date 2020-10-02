#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int ladderfn(int n)
{
	//base case
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	return ladderfn(n-1)+ladderfn(n-2)+ladderfn(n-3);
}

int main()
{
	int n;
	cout<<"Enter the number 'n' the steps of ladder "<<endl;
	cin>>n;
	cout<<ladderfn(n);
	return 0;
}