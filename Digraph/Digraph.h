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
		++e;
		adj[v].push_back(w);
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

class DepthFirstDirectedPaths
{
public:
	DepthFirstDirectedPaths(Digraph DG, int _s)
	{
		marked = vector<bool>(DG.V(), false);
		edgeTo = vector<int>(DG.V(), _s);
		s = _s;
		dfs(DG, _s);
	}

	bool hasPathTo(int v)
	{
		return isMarked(v);
	}

	vector<int> pathTo(int v)
	{
		vector<int> pathToStart;
		if(!hasPathTo(v))
			return pathToStart;

		for(int x = v; x != s; x = edgeTo[x])
			pathToStart.push_back(x);
		pathToStart.push_back(s);
		reverse(pathToStart.begin(), pathToStart.end());
		return pathToStart;
	}

	bool isMarked(int v)
	{
		return marked[v];
	}

private:
	void dfs(Digraph DG, int v)
	{
		marked[v] = true;
		for(auto x: DG.getAdj(v))
		{
			if (!marked[x])
			{
				edgeTo[x] = v;
				dfs(DG, x);
			}
		}
	}

private:
	vector<bool> marked;
	vector<int> edgeTo;
	int s;
};

class BreadthFirstDirectedPaths
{
public:
	BreadthFirstDirectedPaths(Digraph DG, int _s)
	{
		marked = vector<bool>(DG.V(), false);
		edgeTo = vector<int>(DG.V(), _s);
		s = _s;
		bfs(DG, s);
	}

	bool hasPathTo(int v)
	{
		return isMarked(v);
	}

	vector<int> pathTo(int v)
	{
		vector<int> pathToStart;
		if(!hasPathTo(v))
			return pathToStart;

		for(int x = v; x != s; x = edgeTo[x])
			pathToStart.push_back(x);
		pathToStart.push_back(s);
		reverse(pathToStart.begin(), pathToStart.end());
		return pathToStart;
	}

	bool isMarked(int v)
	{
		return marked[v];
	}

private:
	void bfs(Digraph DG, int v)
	{
		queue<int> q;
		q.push(v);
		marked[v] = true;

		while(!q.empty())
		{
			int s = q.front();
			q.pop();
			for(auto x: DG.getAdj(s))
			{
				if(!marked[x])
				{
					q.push(x);
					edgeTo[x] = s;
					marked[x] = true;
				}
			}
		}
	}

private:
	vector<bool> marked;
	vector<int> edgeTo;
	int s;
};
