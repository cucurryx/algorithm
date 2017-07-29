#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
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


class Search
{
public:
	Search(Graph G, int s): vOfs(G.allAdj(s)){}
	bool marked(int v)
	{
		auto x = find(vOfs.begin(), vOfs.end(), v);
		return x != vOfs.end();
	}
	int count()
	{
		return vOfs.size();
	}

private:
	vector<int> vOfs;
};

class DepthFirstSearch
{
public:
	DepthFirstSearch(Graph G, int s)
	{
		marked = vector<bool>(G.V(), false);
		dfs(G, s);
	}

	bool isMarked(int w)
	{
		return marked[w];
	}

	int count()
	{
		return _count;
	}

private:
	void dfs(Graph G, int v)
	{
		marked[v] = true;
		_count++;
		for(auto w: G.allAdj(v))
			if(marked[w] == false)
				dfs(G, w);
	}

private:
	vector<bool> marked;
	int _count;
};


class DepthFirstPaths
{
public:
	DepthFirstPaths(Graph G, int _s)
	{
		marked = vector<bool>(G.V(), false);
		edgeTo = vector<int>(G.V(), _s);
		s = _s;
		dfs(G, s);
	}

	void dfs(Graph G, int v)
	{
		marked[v] = true;
		for(auto w: G.allAdj(v))
			if(!marked[w])
			{
				edgeTo[w] = v;
				dfs(G, w);
			}
	}

	bool hasPathTo(int v)
	{
		return marked[v];
	}

	vector<int> pathTo(int v)
	{
		vector<int> path;
		if(!hasPathTo(v))
			return path;
		for(int x = v ; x != s; x = edgeTo[x])
			path.push_back(x);
		path.push_back(s);
		reverse(path.begin(), path.end());
		return path;
	}

private:
	vector<bool> marked;
	vector<int> edgeTo;
	int s;
};