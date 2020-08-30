#include<iostream>
//#include<algorithm>
#include<time.h>
#include<list>
#include<map>
#include<queue>
#include<climits>
//#include<arithmetic.h>
using namespace std;
template <typename T>
class graph
{
private:
	map<T,list<T>> l;
public:
	void add_edge(T x, T y)
	{
		l[x].push_back(y);
		//l[y].push_back(x);
	}

	void display()
	{
		for(auto i:l)
		{
			T node=i.first;
			cout<<node<<" -> ";
			list<T>nbr=i.second;
			for(auto j:l[node])
			{
				cout<<j<<",";

			}
			cout<<endl;
		}
	}
	void dfs_helper(T src,map<T,bool> &visited,list<T> &ordering)
	{
		visited[src]=true;
		for(auto nbr:l[src])
		{
			if(!visited[nbr])
				dfs_helper(nbr,visited,ordering);
		}
		ordering.push_front(src);
		return;
	}

	void dfs(T src)
	{
		map<T,bool> visited;
		list<T> ordering;

		for(auto p:l)
		{
			T node = p.first;
			visited[node]=false;
		}

		for(auto i:l)
		{
			T node = i.first;
			if(!visited[node])
				dfs_helper(node,visited,ordering);
		}

		cout<<"ordering :"<<endl;
		for(auto node : ordering)
		{
			cout<<node<<endl;
		}
	}

	


};

int main()
{
	graph<string> g;
	g.add_edge("python","data preprocessing");
	g.add_edge("python","pytorch");
	g.add_edge("data preprocessing","ML Basics");
	g.add_edge("pytorch","deep learning");
	g.add_edge("ML Basics","deep learning");
	g.add_edge("deep learning","face Recognition");
	g.add_edge("dataset","face Recognition");

	g.display();
	g.dfs("python");
	return 0;
}