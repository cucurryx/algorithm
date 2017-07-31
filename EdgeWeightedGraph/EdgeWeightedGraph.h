#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


class Edge
{
	friend bool operator<(Edge a, Edge b);
public:
	Edge(int _v, int _w, double _weight):
	v(_v), w(_w), edgeWeight(_weight){}

	double weight() { return edgeWeight; }
	int either() { return v; }

	int other(int _v)
	{
		if(v == _v)
			return w;
		else if(w == _v)
			return v;
		else
			throw runtime_error("Inconsistent edge");
	}

	int compareTo(Edge that)
	{
		if(edgeWeight < that.weight())
			return -1;
		else if(edgeWeight > that.weight())
			return 1;
		else
			return 0;
	}
private:
	int v;
	int w;
	double edgeWeight;
};

bool operator<(Edge a, Edge b)
{
	if(a.weight() < b.weight())
		return true;
	else
		return false;
}

class EdgeWeightedGraph
{
public:
	EdgeWeightedGraph(int _v)
	{
		v = _v;
		e = 0;
		adj = vector<vector<Edge>>(_v, vector<Edge>());
	}

	void addEdge(Edge edge)
	{
		int v = edge.either();
		int w = edge.other(v);
		adj[v].push_back(edge);
		adj[w].push_back(edge);
		++e;
	}

	vector<Edge> edges()
	{
		vector<Edge> allEdge;
		for(int i = 0; i < v; ++i)
			for(Edge x: adj[i])
				if(x.other(i) > i)
					allEdge.push_back(x);
		return allEdge;
	}

	int V(){ return v; }
	int E(){ return e; }
	vector<Edge> getAdj(int v) { return adj[v]; }

private:
	vector<vector<Edge>> adj;
	int v;
	int e;
};

class LazyPrimMST
{
public:
	LazyPrimMST(EdgeWeightedGraph G)
	{
		marked = vector<bool>(G.V(), false);
		visit(G, 0);
		while(!pq.empty())
		{
			Edge e = pq.top();
			pq.pop();

			int v = e.either(), w = e.other(v);
			if(marked[v] && marked[w])
				continue;
			mst.push_back(e);
			if(!marked[v])
				visit(G, v);
			if(!marked[w])
				visit(G, w);

		}
	}

	vector<Edge> edges()
	{
		return mst;
	}

	double weight()
	{
		double w;
		for(auto x: mst)
			w += x.weight();
		return w;
	}

private:
	void visit(EdgeWeightedGraph G, int v)
	{
		marked[v] = true;
		for(auto x: G.getAdj(v))
			if(!marked[x.other(v)])
				pq.push(x);
	}

private:
	vector<Edge> mst;
	priority_queue<Edge> pq;
	vector<bool> marked;
};
