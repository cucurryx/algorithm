#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;

class DirectedEdge
{
public:
	DirectedEdge(int v, int w, double _edgeWeight):
		begin(v), end(w), edgeWeight(_edgeWeight){}
	double weight() { return edgeWeight; }
	int from() { return begin; }
	int to() { return end; }

private:
	int begin;
	double edgeWeight;
	int end;
};

class EdgeWeightedDigraph
{
public:
	EdgeWeightedDigraph(int _v)
	{
		adj = vector<vector<DirectedEdge>>(_v, vector<DirectedEdge>());
		v = _v;
		e = 0;
	}

	int V() { return v; }
	int E() { return e; }

	void addEdge(DirectedEdge de)
	{
		adj[de.from()].push_back(de);
		++e;
	}

	vector<DirectedEdge> getAdj(int v)
	{
		return adj[v];
	}

	vector<DirectedEdge> edges()
	{
		vector<DirectedEdge> allEdge;
		for(auto x: adj)
			for(auto y: x)
				allEdge.push_back(y);
		return allEdge;
	}

private:
	vector<vector<DirectedEdge>> adj;
	int v;
	int e;
};
