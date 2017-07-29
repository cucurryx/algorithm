#include "Graph.h"

int main()
{
    Graph gra(10);
    gra.addEdge(0, 5);
    gra.addEdge(2, 4);
    gra.addEdge(2, 3);
    gra.addEdge(1, 2);
    gra.addEdge(0, 1);
    gra.addEdge(3, 4);
    gra.addEdge(3, 5);
    gra.addEdge(0, 2);

    DepthFirstPaths search(gra, 0);
    BreadthFirstPaths searchBFS(gra, 0);

    cout << "DFS:" << endl;
    for(int v = 0; v < gra.V(); ++v)
    {
        cout << 0 << " to " << v << ": ";
        if(search.hasPathTo(v))
        {
            vector<int> path = search.pathTo(v);
            for (int i = 0; i < path.size(); ++i)
                if (path[i] == 0)
                    cout << path[i];
                else
                    cout << "-" << path[i];
        }
        cout << endl;
    }

    cout << "\nBFS:" << endl;
    for(int v = 0; v < gra.V(); ++v)
    {
        cout << 0 << " to " << v << ": ";
        if(searchBFS.hasPathTo(v))
        {
            vector<int> path = searchBFS.pathTo(v);
            for (int i = 0; i < path.size(); ++i)
                if (path[i] == 0)
                    cout << path[i];
                else
                    cout << "-" << path[i];
        }
        cout << endl;
    }

    CC cc(gra);
    cout << "\nGraph gra has " << cc.count() << " components" << endl;

    return 0;
}
