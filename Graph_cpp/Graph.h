#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
	Graph(int _v): v(_v), e(0), adj(_v, vector<int>()){}
	int V(){return v;}
	int E(){return e;}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
		++e;
	}
	vector<int>& allAdj(int v){return adj[v];}

private:
	int v;
	int e;
	vector<vector<int>> adj;
};
