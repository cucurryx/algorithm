#include "ShortestPath.h"

int main()
{
	ifstream in("tinyEWD.txt");
	int graphSize;
	in >> graphSize;

	EdgeWeightedDigraph G(graphSize);
	int v, w;
	double weight;
	while(in >> v >> w >> weight)
		G.addEdge(DirectedEdge(v, w, weight));
	cout << G.V() << " " << G.E() << endl;

	DijkstraSP DPS(G, 0);
	for(int i = 0; i < G.V(); ++i)
	{
		cout << 0 << " to " << i;
		cout << " (" << DPS.getDistTo(i) << "):";

		vector<DirectedEdge> edges = DPS.pathTo(i);
		for(DirectedEdge e: edges)
			printf(" %d->%d %.2lf ", e.from(), e.to(), e.weight());
		cout << endl;
	}

	return 0;
}
