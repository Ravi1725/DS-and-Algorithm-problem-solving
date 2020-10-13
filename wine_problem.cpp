#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int profit(int prices[],int i,int j,int year,int dp[][100])
{
	//Base case
	if(i==j)
	{
		return (prices[i]*year);
	}

	//lookup condition
	if(dp[i][j]!=0)
	{
		return dp[i][j];
	}
	if(i<=j)
	{
		
		int x =prices[i]*year + profit(prices,i+1,j,year+1,dp);
		
		int y =prices[j]*year + profit(prices,i,j-1,year+1,dp);
		
		dp[i][j]=max(x,y);
		//cout<<dp[i][j]<<endl;
	}
	return dp[i][j];
}

int main()
{
	int prices[]={2,1,4,7,5};
	int dp[100][100]={0};
	int n=sizeof(prices)/sizeof(int);
	cout<<profit(prices,0,n-1,1,dp)<<endl;
	return 0;
}