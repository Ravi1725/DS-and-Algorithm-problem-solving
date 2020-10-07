//N Queen problem
//It will print all possible structues.
#include<iostream>
using namespace std;

bool is_perfect(int board[][100], int i, int j,int n)
{
	//column check
	for(int row=0;row<n;row++)
	{
		if(board[row][j]==1)
			return false;
	}
	int x=i;
	int y=j;
	//left diagonal
	while(x>=0&& y<n)
	{
		if(board[x][y]==1)
			return false;
		x--;
		y--;
	}

	x=i;
	y=j;
	//right diagonal
	while(x>=0&& y<n)
	{
		if(board[x][y]==1)
			return false;
		x--;
		y++;
	}

	
	return true;
}

bool n_queen(int board[][100],int n,int i)
{
	//base case
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}

		cout<<endl;
		return false;
	}

	//recursive case
	for(int j=0;j<n;j++)
	{
		if(is_perfect(board,i,j,n))
		{
			board[i][j]=1;
			if(n_queen(board,n,i+1))
			{
				return true;
			}
			board[i][j]=0; //backtrck
		}
	}
	return false;
	
}  
int main()
{
	int board[100][100]={0};
	int n;
	cout<<"Enter the value of n"<<endl;
	cin>>n;
	n_queen(board,n,0);
	
	return 0;
}