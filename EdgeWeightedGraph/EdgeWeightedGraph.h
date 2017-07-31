#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

class Edge
{
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
		if(that.weight() < edgeWeight)
			return 1;
		else if(that.weight() > edgeWeight)
			return -1;
		else
			return 0;
	}

private:
	int v;
	int w;
	double edgeWeight;
};

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
