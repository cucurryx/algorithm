#include "EdgeWeightedGraph.h"

int main()
{
	ifstream in("MediumEWG.txt");
	int graphSize;
	in >> graphSize;

	EdgeWeightedGraph EWG(graphSize);
	int w, v;
	double weight;
	while(in >> w >> v >> weight)
		EWG.addEdge(Edge(w, v, weight));
	cout << EWG.V() << " " << EWG.E() << endl;

	return 0;
}
