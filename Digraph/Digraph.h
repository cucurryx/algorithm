#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Digraph
{
public:
	Digraph(int _v): v(_v), e(0)
	{
		adj = vector<vector<int>>(_v, vector<int>());
	}

	vector<int> getAdj(int v) { return adj[v]; }
	int V() { return v; }
	int E()	{ return e;	}

	void addEdge(int v, int w)
	{
		if(find(adj[v].begin(), adj[v].end(), w) == adj[v].end())
		{
			++e;
			adj[v].push_back(w);
		}
	}

	Digraph reverse()
	{
		Digraph dg(v);
		for(int i = 0; i < v; ++i)
			for(auto x: adj[i])
				dg.addEdge(x, i);
		return dg;
	}

private:
	vector<vector<int>> adj;
	int v;
	int e;
};


class DirectedDFS
{
public:
	DirectedDFS(Digraph G, int s)
	{
		marked = vector<bool>(G.V(), false);
		dfs(G, s);
	}

	DirectedDFS(Digraph G, vector<int> sources)
	{
		marked = vector<bool>(G.V(), false);
		for(auto x: sources)
			dfs(G, x);
	}

	bool isMarked(int v)
	{
		return marked[v];
	}

private:
	void dfs(Digraph G, int v)
	{
		marked[v] = true;
		for(auto x: G.getAdj(v))
		{
		 	if(!isMarked(x))
				dfs(G, x);
		}
	}

private:
	vector<bool> marked;
};
