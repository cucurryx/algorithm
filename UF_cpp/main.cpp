#include <iostream>
#include <fstream>
#include <time.h>
#include "union_find.h"
#include "weighted_union_find.h"
using namespace std;

int main()
{
	ifstream in("test_large.txt");
	int N;
	in>>N;

    union_find uf(N);
//	weighted_union_find uf_w(N);

	int begin = clock();
    for(int i = 0; i < 50; ++i)
	{
		int p, q;
		in>>p>>q;
	//	uf_w._union(p, q);
        uf._union(p, q);
	}
	int end = clock();

    cout << "quick_union| " << "area: " << uf.count()
	<< "  time: "<<(end-begin)/1000000.0 <<"s"<< endl;
	//cout << "weighted_quick_union| " << "area: " << uf_w.count()
	//<< "  time: "<<(end-begin)/1000000.0 <<"s"<< endl;

	return 0;
}

/****************测试结果 100w数据 200w连接**************
 *quick_find| area: 999950  time: 0.593439s
 *quick_union| area: 999950  time: 2.6e-05s
 *weighted_quick_union| area: 999950  time: 3.1e-05s
 *****************************************************/
