#include "Graph.h"

int main()
{
	ifstream in("routes.txt");
	SymbolGraph SG(in);
	Graph G = SG.getGraph();

	cout << G.E() << endl;
	cout << G.V() << endl;

	for(int i = 0; i < 7; ++i)
	{
		for(auto x: G.allAdj(i))
			cout << x << " ";
		cout << endl;
	}

	string source;
	while(getline(cin, source))
	{
		for(auto w: G.allAdj(SG.index(source)))
			cout << "  " << SG.name(w) << endl;
	}

	return 0;
}
