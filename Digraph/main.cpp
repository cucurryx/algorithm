#include "Digraph.h"

int main()
{
	ifstream in("tinyDG.txt");
	Digraph G(13);

	int x, y;
	while(in >> x >> y)
		G.addEdge(x, y);

	vector<int> sources{1, 2, 6, 3};
	DirectedDFS ddfs(G, sources);

	for(int i = 0; i < G.V(); ++i)
		if(ddfs.isMarked(i))
			cout << i << " ";
	cout << endl;

	return 0;
}
