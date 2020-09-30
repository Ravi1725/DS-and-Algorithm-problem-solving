#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

//calculating power in order O(N)
int power(int a,int n)
{
	if(n==0)
		return 1;
	else
		return a*power(a,n-1);
}
//for calculating in time complexity O(log n)
int power_min(int a, int n)
{
	if(n==0)
		return 1;
	else
	{
		int temp=power_min(a,n/2);
		if(n%2==0)
			return temp*temp;
		else
			return a*temp*temp;
	}
}

//recursive function to multiply two number without * operator
int multiply(int a,int b)
{
	if(a==1)
		return b;
	else
		return b+multiply(a-1,b);
}

int main()
{
	cout<<power(2,5)<<endl;
	cout<<power_min(2,6)<<endl;
	cout<<multiply(8,9);
	return 0;
}