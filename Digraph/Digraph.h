#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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

class DirectedCycle
{
public:
	DirectedCycle(Digraph G)
	{
		marked = vector<bool>(G.V(), false);
		edgeTo = vector<int>(G.V(), 0);
		onStack = vector<bool>(G.V(), false);
		for(int v = 0; v < G.V(); ++v)
			dfs(G, v);
	}

	bool hasCycle()
	{
		return !cycle.empty();
	}

	vector<int> getCycle()
	{
		vector<int> cycleVec;
		while(!cycle.empty())
		{
			cycleVec.push_back(cycle.top());
			cycle.pop();
		}
		return cycleVec;
	}
private:
	void dfs(Digraph G, int v)
	{
		onStack[v] = true;
		marked[v] = true;
		for(int w: G.getAdj(v))
		{
			if(hasCycle())
				return;
			else if(!marked[w])
			{
				edgeTo[w] = v;
				dfs(G, w);
			}
			else if(onStack[w])
			{
				for(int x = v; x != w; x = edgeTo[x])
					cycle.push(x);
				cycle.push(w);
				cycle.push(v);
			}
		}
		onStack[v] = false;
	}

private:
	vector<bool> marked;
	vector<int> edgeTo;
	stack<int> cycle;
	vector<bool> onStack;
};

class DepthFirstOrder
{
public:
	DepthFirstOrder(Digraph G)
	{
		marked = vector<bool>(G.V(), false);
		for(int v = 0; v < G.V(); ++v)
			if(!marked[v])
				dfs(G, v);
	}

	vector<int> preOrder()
	{
		return pre;
	}

	vector<int> postOrder()
	{
		return post;
	}

	vector<int> reversePostOrder()
	{
		reverse(reversePost.begin(), reversePost.end());
		return reversePost;
	}

private:
	void dfs(Digraph G, int v)
	{
		pre.push_back(v);
		marked[v] = true;
		for(auto x: G.getAdj(v))
		{
			if(!marked[x])
				dfs(G, x);
		}
		post.push_back(v);
		reversePost.push_back(v);
	}

private:
	vector<bool> marked;
	vector<int> pre;
	vector<int> post;
	vector<int> reversePost;
};

//拓扑排序
class Topological
{
public:
	Topological(Digraph G)
	{
		DirectedCycle cycleJudge(G);
		if(!cycleJudge.hasCycle())
		{
			DepthFirstOrder dfs(G);
			orderVec = dfs.reversePostOrder();
		}
	}

	vector<int> order()
	{
		return orderVec;
	}

	bool isDAG()
	{
		return !orderVec.empty();
	}

private:
	vector<int> orderVec;
};

// find all strongly connected components
// use the Kosaraju algorithm
class SCC
{
public:
	SCC(Digraph G)
	{
		marked = vector<bool>(G.V(), false);
		id = vector<int>(G.V(), 0);
		cnt = 0;

		DepthFirstOrder dfsOrder(G.reverse());
		for(auto x: dfsOrder.reversePostOrder())
			if(!marked[x])
			{
				dfs(G, x);
				++cnt;
			}
	}

	bool stronglyConnected(int v, int w)
	{
		return id[v] == id[w];
	}

	int count()
	{
		return cnt;
	}

	int getID(int v)
	{
		return id[v];
	}

	vector<vector<int>> components()
	{
		vector<vector<int>> comp(count(), vector<int>());
		for(int i = 0; i < id.size(); ++i)
			comp[id[i]].push_back(i);
		return comp;
	}

private:
	void dfs(Digraph G, int v)
	{
		marked[v] = true;
		id[v] = cnt;
		for(auto x: G.getAdj(v))
			if(!marked[x])
				dfs(G, x);
	}

private:
	vector<bool> marked;
	vector<int> id;
	int cnt;
};
