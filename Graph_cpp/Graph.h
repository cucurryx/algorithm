#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <queue>
#include <map>
using namespace std;

class Graph
{
public:
	Graph(int _v): v(_v), e(0), adj(_v, vector<int>()){}
	Graph(): v(0), e(0){}
	int V(){return v;}
	int E(){return e;}
	void addEdge(int v, int w)
	{
		if(find(adj[v].begin(), adj[v].end(), w) == adj[v].end())
			adj[v].push_back(w);
		if(find(adj[w].begin(), adj[w].end(), v) == adj[w].end())
			adj[w].push_back(v);
		++e;
	}
	vector<int>& allAdj(int v){return adj[v];}

private:
	int v;
	int e;
	vector<vector<int>> adj;
};

class SymbolGraph
{
public:
	SymbolGraph(ifstream& stream)
	{
		string strOne, strTwo;
		vector<pair<string, string>> pairs;

		while(stream >> strOne >> strTwo )
		{
			pairs.push_back(make_pair(strOne, strTwo));
			if(find(keys.begin(), keys.end(), strOne) == keys.end())
				keys.push_back(strOne);
			if(find(keys.begin(), keys.end(), strTwo) == keys.end())
				keys.push_back(strTwo);
		}

		for(int i = 0; i < keys.size(); ++i)
			st[keys[i]] = i;

		G = Graph(keys.size());
		for(auto x: pairs)
			G.addEdge(st[x.first], st[x.second]);
	}

	bool contains(string s)
	{
		return find(keys.begin(), keys.end(), s) != keys.end();
	}

	int index(string s)
	{
		return st[s];
	}

	string name(int v)
	{
		return keys[v];
	}

	Graph getGraph()
	{
		return G;
	}

private:
	Graph G;
	map<string, int> st;
	vector<string> keys;
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

class BreadthFirstPaths
{
public:
	BreadthFirstPaths(Graph G, int _s)
	{
		marked = vector<bool>(G.V(), false);
		edgeTo = vector<int>(G.V(), s);
		s = _s;
		bfs(G, s);
	}

	void bfs(Graph G, int s)
	{
		queue<int> q;
		marked[s] = true;
		q.push(s);
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
			for(auto w: G.allAdj(v))
				if(!marked[w])
				{
					edgeTo[w] = v;
					marked[w] = true;
					q.push(w);
				}
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
		for(int x = v; x != s; x = edgeTo[x])
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

//计算连通分量
class CC
{
public:
	CC(Graph G)
	{
		marked = vector<bool>(G.V(), false);
		_id = vector<int>(G.V(), 0);
		_count = 0;
		for(int s = 0; s < G.V(); ++s)
			if(!marked[s])
			{
				dfs(G, s);
				_count++;
			}
	}

	void dfs(Graph G, int v)
	{
		marked[v] = true;
		_id[v] = _count;
		for(auto x: G.allAdj(v))
			if(!marked[x])
				dfs(G, x);
	}

	bool connected(int v, int w)
	{
		return id(v) == id(w);
	}

	int id(int v)
	{
		return _id[v];
	}

	int count()
	{
		return _count;
	}

private:
	vector<bool> marked;
	vector<int> _id;
	int _count;
};
