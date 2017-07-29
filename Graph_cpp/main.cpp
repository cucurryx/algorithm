#include "Graph.h"

int main()
{
    Graph gra(10);
    gra.addEdge(2, 4);
    gra.addEdge(0, 3);
    gra.addEdge(0, 7);
    gra.addEdge(2, 7);

    DepthFirstPaths search(gra, 0);
    for(int v = 0; v < gra.V(); ++v)
    {
        cout << 0 << " to " << v << ": ";
        if(search.hasPathTo(v) == true)
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

    return 0;
}