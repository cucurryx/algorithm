#include "EdgeWeightedGraph.h"
#include "../UF_cpp/weighted_union_find.h"

class KruskalMST
{
public:
	KruskalMST(EdgeWeightedGraph G)
	{
		priority_queue<Edge> pq;
		for(Edge e: G.edges())
			pq.push(e);
		weighted_union_find uf(G.V());
		while(!pq.empty() && mst.size() < G.V()-1)
		{
			Edge e = pq.top();
			pq.pop();
			int v = e.either(), w = e.other(v);
			if(uf.connected(v, w))
				continue;
			uf._union(w, v);
			mst.push_back(e);
		}
	}

	vector<Edge> edges()
	{
		return mst;
	}

	double weight()
	{
		double w = 0.0;
		for(auto x: mst)
			w += x.weight();
		return w;
	}

private:
	vector<Edge> mst;
};
