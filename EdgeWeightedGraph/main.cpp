#include "Kruskal.h"

int main()
{
	ifstream in("1000EWG.txt");
	int graphSize;
	in >> graphSize;

	EdgeWeightedGraph EWG(graphSize);
	int w, v;
	double weight;
	while(in >> w >> v >> weight)
		EWG.addEdge(Edge(w, v, weight));
	cout << EWG.V() << " " << EWG.E() << endl;

	LazyPrimMST LMST(EWG);
	vector<Edge> mst = LMST.edges();
	cout << "The mst weight(Prim): " << LMST.weight() << endl;
	cout << "The mst: " << endl ;
	for(auto x: mst)
		cout << x.either() << "-" << x.other(x.either()) << endl;

	KruskalMST KMST(EWG);
	vector<Edge> kmst = KMST.edges();
	cout << "The mst weight(Kruskal):" << KMST.weight() << endl;
	cout << "The mst: " << endl;
	for(auto x: kmst)
		cout << x.either() << "-" << x.other(x.either()) << endl;

	return 0;
}
