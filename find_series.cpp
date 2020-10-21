#include<iostream>
using namespace std;
int fibonicci(int num)
{
	int dp[num]={0};

	//base case
	dp[1]=1;
	dp[2]=1;

	for(int i=3;i<=num;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[num];
}

int prime_no(int num)
{
	int c=0;
	int flag;
	int arr[num];
	arr[c++]=2;
	for(int i=3;c<=num;i++)
	{
		flag=1;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			arr[c++]=i;
		}
	}
	return arr[num-1];
}
int main()
{
	int n;
	cout<<"Input the value of n"<<endl;
	cin>>n;

	if(n%2==0)
	{
		int num= n/2;
		cout<<prime_no(num)<<endl;
	}
	if(n%2!=0)
	{
		int num=n/2+1;
		cout<<fibonicci(num)<<endl;
	}
	return 0;
}