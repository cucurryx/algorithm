#include <iostream>
#include "union_find.h"
#include "weighted_union_find.h"
using namespace std;

int main()
{
    union_find uf(101);
	weighted_union_find uf_w(101);

    for(int i = 0; i < 50; ++i)
	{
		uf_w._union(i, 100-i);
        uf._union(i, 100-i);
	}

	uf._union(1, 4);
	uf._union(1, 99);

	uf_w._union(1, 4);
	uf_w._union(1, 4);

    cout << uf.count() << endl;
	cout << uf_w.count() << endl;

	return 0;
}
