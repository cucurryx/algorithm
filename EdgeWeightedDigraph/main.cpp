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

	return 0;
}
