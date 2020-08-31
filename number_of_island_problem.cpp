#include<iostream>
//#include<algorithm>
#include<time.h>
#include<list>
#include<map>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<char>>& grid,int m,int n, int i,int j)
	{
		grid[i][j]='2';
		if(i<0 | j<0 | i>=m | j>=n |grid[i][j]=='0')
			return;

		int mat[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
		for(int i=0;i<4;i++)
		{
			dfs(grid,m,m,i+mat[i][0],j+mat[i][1]);
		}
	}
    int numIslands(vector<vector<char>>& grid) {
    	if(grid.size()==0) return 0;
    	int m=grid.size();
    	int n=grid[0].size();
    	int count=0;
    	for(int i=0;i<m;i++)
    	{
    		for(int j=0;j<n;j++)
    		{
    			if(grid[i][j]=='1')
    			{
    				count++;
    				dfs(grid,m,n,i,j);
    			}
    		}
    	}
     return count;   
    }
};

int main()
{
	class Solution g;
	vector<vector<char>> grid= {
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
};
	int value=g.numIslands(grid);
	cout<<value<<endl;
}