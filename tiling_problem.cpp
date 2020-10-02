//given the wall of 4xn. and tiles is of size of 4x1 and 1x4, In how many ways we can build wall.
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int possibility_tiling(int n)
{
	//base case
	if(n<=3)
		return 1;
	if(n==4)
		return 2;

	//recursive step
	return possibility_tiling(n-1)+possibility_tiling(n-4);
}

int main()
{
	int n;
	cout<<"Enter the value of n"<<endl;
	cin>>n;
	cout<<possibility_tiling(n)<<endl;
	return 0;
}