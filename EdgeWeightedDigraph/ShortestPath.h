#include "EdgeWeightedDigraph.h"
#include <float.h>

class IndexPQ
{
public:
	IndexPQ() { count = 0; }
	IndexPQ(int v)
	{
		vec = vector<double>(v, DBL_MAX);
		count = 0;
	}

	bool empty() { return count == 0; }

	int delMin()
	{
		int del = 0;
		double min = vec[0];
		for(int i = 0; i < vec.size(); ++i)
		{
			if(vec[i] < min)
				del = i;
		}
		vec[del] = DBL_MAX;
		--count;
		return del;
	}

	void insert(int pos, double val)
	{
		++count;
		vec[pos] = val;
	}

	void change(int pos, double val) { vec[pos] = val; }
	bool contains(int i) { return vec[i] != DBL_MAX; }

private:
	vector<double> vec;
	int count;
};

/******************Dijkstra********************
/* 从最起点开始，每次都对队列中最小的那个边进行放松,
/* relax(), 根据归纳法，局部最优保证了整体最优
**********************************************/
class DijkstraSP
{
public:
	DijkstraSP(EdgeWeightedDigraph G, int _s)
	{
		s = _s;
		edgeTo = vector<DirectedEdge>(G.V(), DirectedEdge(0, 0, 0));
		distTo = vector<double>(G.V(), DBL_MAX);
		distTo[s] = 0;
		pq = IndexPQ(G.V());
		marked = vector<bool>(G.V(), false);

		pq.insert(s, 0.0);
		while(!pq.empty())
			relax(G, pq.delMin());
	}

	double getDistTo(int v) { return distTo[v]; }
	bool hasPathTo(int v) { return marked[v]; }

	vector<DirectedEdge> pathTo(int v)
	{
		vector<DirectedEdge> pathToV;
		if(!hasPathTo(v))
			return pathToV;
		for(int x = v; x != s; x = edgeTo[x].from())
			pathToV.push_back(edgeTo[x]);
		reverse(pathToV.begin(), pathToV.end());
		return pathToV;
	}
private:
	// 边的松弛
	void relax(DirectedEdge edge)
	{
		int v = edge.from(), w = edge.to();
		marked[v] = true;
		marked[w] = true;
		if(distTo[w] > distTo[v] + edge.weight())
		{
			distTo[w] = distTo[v] + edge.weight();
			edgeTo[w] = edge;
		}
	}

	// 顶点的松弛
	void relax(EdgeWeightedDigraph G, int v)
	{
		for(DirectedEdge edge: G.getAdj(v))
		{
			int w = edge.to();
			marked[w] = true;
			marked[v] = true;
			if(distTo[w] > distTo[v] + edge.weight())
			{
				distTo[w] = distTo[v] + edge.weight();
				edgeTo[w] = edge;
				if(pq.contains(w))
					pq.change(w, distTo[w]);
				else
					pq.insert(w, distTo[w]);
			}
		}
	}

private:
	vector<DirectedEdge> edgeTo;
	vector<double> distTo;
	vector<bool> marked;
	IndexPQ pq;
	int s;
};

/**************AcyclicSP*****************
/* 该算法适用于无环加权图的最短路径寻找，可以在
/* 线性时间内完成，具体就是按照该图拓扑排序的顺序
/* 放松所有的顶点
***************************************/

class Topological
{
public:
	Topological(EdgeWeightedDigraph G)
	{
		marked = vector<bool>(G.V(), false);
		for(int v = 0; v < G.V(); ++v)
			if(!marked[v])
				dfs(G, v);
	}

	vector<int> order()
	{
		reverse(_order.begin(), _order.end());
		return _order;
	}

private:
	void dfs(EdgeWeightedDigraph G, int v)
	{
		marked[v] = true;
		for(auto x: G.getAdj(v))
			if(!marked[x.to()])
				dfs(G, x.to());
		_order.push_back(v);
	}

private:
	vector<bool> marked;
	vector<int> _order;
	int s;
};

class AcyclicSP
{
public:
	AcyclicSP(EdgeWeightedDigraph G, int _s)
	{
		s = _s;
		distTo = vector<double>(G.V(), DBL_MAX);
		distTo[0] = 0;
		edgeTo = vector<DirectedEdge>(G.V(), DirectedEdge(0, 0, 0));

		Topological top(G);
		for(auto x: top.order())
			relax(G, x);
	}

	double getDistTo(int v) { return distTo[v]; }
	bool hasPathTo(int v){ return distTo[v] != DBL_MAX; }

	vector<DirectedEdge> pathTo(int v)
	{
		vector<DirectedEdge> path;
		if(!hasPathTo(v))
			return path;
		for(int x = v; x != s; x = edgeTo[x].from())
			path.push_back(edgeTo[x]);
		reverse(path.begin(), path.end());
		return path;
	}
private:
	void relax(EdgeWeightedDigraph G, int v)
	{
		for(auto e: G.getAdj(v))
		{
			int w = e.to();
			if(distTo[w] > distTo[v] + e.weight())
			{
				distTo[w] = distTo[v] + e.weight();
				edgeTo[w] = e;
			}
		}
	}

private:
	vector<double> distTo;
	vector<DirectedEdge> edgeTo;
	int s;
};
