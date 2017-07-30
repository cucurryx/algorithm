#include "Digraph.h"

int main()
{
	ifstream in("tinyDG.txt");
	Digraph G(13);

	int x, y;
	while(in >> x >> y)
		G.addEdge(x, y);

// Test of directed graph DFS
	DepthFirstDirectedPaths DP(G, 4);
	vector<vector<int>> pathsDFS(G.V(), vector<int>());
	for(int i = 0; i < G.V(); ++i)
		pathsDFS[i] = DP.pathTo(i);

	cout << "DFS:" << endl;
	for(int i = 0; i < G.V(); ++i)
	{
		cout << "4 to " << i << "'s path: ";
		if(pathsDFS[i].empty())
		{
			cout << "no path from 4 to " << i << endl;
			continue;
		}

		for(auto x: pathsDFS[i])
			if(x == 4)
				cout << x;
			else
				cout << " - " << x;
		cout << endl;
	}

	// Test of directed graph BFS
	BreadthFirstDirectedPaths BP(G, 4);
	vector<vector<int>> pathsBFS(G.V(), vector<int>());
	for(int i = 0; i < G.V(); ++i)
		pathsBFS[i] = BP.pathTo(i);

	cout << "\nBFS:" << endl;
	for(int i = 0; i < G.V(); ++i)
	{
		cout << "4 to " << i << "'s path: ";
		if(pathsBFS[i].empty())
		{
			cout << "no path from 4 to " << i << endl;
			continue;
		}

		for(auto x: pathsBFS[i])
			if(x == 4)
				cout << x;
			else
				cout << " - " << x;
		cout << endl;
	}
	return 0;
}
