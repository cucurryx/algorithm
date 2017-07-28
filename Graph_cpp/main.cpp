#include "Graph.h"

int main()
{
    Graph gra(10);
    for(int i = 0; i < 9; ++i)
        gra.addEdge(i, i+1);
    gra.addEdge(1, 9);
    gra.addEdge(9, 1);

    cout << gra.V() << endl;
    cout << gra.E() << endl;

    vector<int> a = gra.allAdj(1);
    for(auto x: a)
        cout << x << endl;

    return 0;
}