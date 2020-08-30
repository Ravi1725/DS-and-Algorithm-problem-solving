#include<iostream>
#include<algorithm>
#include<time.h>
#include<list>
//#include<arithmetic.h>
using namespace std;

class graph
{
private:
	int v;
	list<int> *l;

public:
	graph(int v)
	{
		this->v=v;
		l=new list<int>[v];
	}
	void add_edge(int x,int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void display_graph()
	{
		for(int i=0;i<v;i++)
		{
			cout<<"Vertics" <<i<<"  -> ";
			for(int nbr:l[i])
			{
				cout<<nbr<<" , ";
			}
			cout<<endl;
		}
	}
};

int main()
{
	graph g(4);
	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(1,2);
	g.add_edge(2,3);

	g.display_graph();
	return 0;
}