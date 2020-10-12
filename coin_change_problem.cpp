#include<iostream>
#include<cstring>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;

int coin_change(int coin[],int n,int k,int dp[])
{
	//base case
	if(k==0)
	{
		return 0;
	}

	int value=INT_MAX;

	if(dp[n!=0])
		return dp[n];
	//recursive case
	for(int itr=0; itr<n; itr++)
	{

		if(k-coin[itr]>=0)
		{
			int count=coin_change(coin,n,k-coin[itr],dp);
			value=min(value,count+1);
		}
		
		
	}
	dp[k]=value;
	return dp[k];
}

int main()
{
	int dp[100]={0};
	int coin[]={1,2,7};
	int k=52;
	int n=sizeof(coin)/sizeof(int);
	cout<<coin_change(coin,n,k,dp)<<endl;
	return 0;
}