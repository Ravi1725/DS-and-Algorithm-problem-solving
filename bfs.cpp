//Implementation of BFS traversal as well as single source shortest path algorithm.
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
		l[y].push_back(x);
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

	void bsf_traversal(T src)
	{
		map<T,bool>visited;
		queue<T> q;

		q.push(src);
		visited[src]=true;

		while(!q.empty())
		{
			T node=q.front();
			cout<<node<<" , ";
			q.pop();
			for(auto nbr:l[node])
			{
				if(!visited[nbr])
				{
					visited[nbr]=true;
					q.push(nbr);
				}
			}
		}
	}

	int bsf(T src, T dest)
	{
		map<T,int>dist;
		queue<T> q;
		for(auto node_list : l)
		{
			T node=node_list.first;
			dist[node]=INT_MAX;
		}
		q.push(src);
		dist[src]=0;
		while(!q.empty())
		{
			T node=q.front();
			q.pop();
			for(auto i : l[node])
			{
				if(dist[i]==INT_MAX)
				{
					q.push(i);
					dist[i]=dist[node]+1;
				}
			}
		}

		return dist[dest];
	}


};

int main()
{
	graph<int> g;
	g.add_edge(0,1);
	g.add_edge(0,3);
	g.add_edge(1,2);
	g.add_edge(2,3);
	g.add_edge(3,4);
	g.add_edge(4,5);

	g.display();
	g.bsf_traversal(0);
	int i=g.bsf(0,4);
	cout<<endl;
	cout<<i<<endl;
	return 0;
}