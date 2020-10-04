#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int profit(int *wt,int *price, int n, int c)
{
	//base case
	if(n==0 || c==0)
		return 0;

	//Recursive case
	//when weight is included
	int included=0,excluded=0;
	int result =0;
	if(wt[n-1]<=c)
	{
		included=price[n-1] + profit(wt,price,n-1,c-wt[n-1]);
	}
	excluded=profit(wt,price,n-1,c);
	result=max(included,excluded);
	return result;
}

int main()
{
	int wt[]={1,2,3,5,4};
	int price[]={40,20,10,30,60};
	int c,n=5;
	cout<<"Enter the value of capacity(C)"<<endl;
	cin>>c;
	cout<<profit(wt,price,n,c)<<endl;
	return 0;
}