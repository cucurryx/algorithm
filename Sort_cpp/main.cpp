#include "Sort.h"
// sort(T*, int)
// sort(vector<T>&)

int main()
{
	Sort<int> sort;
	vector<int> vec;
	for(int i = 1; i != 10000; ++i)
	{
		auto num = static_cast<int> (rand());
		vec.push_back(num);
	}
	sort.shellSort(vec);
	sort.insertSort(vec);
	sort.selecteSort(vec);
	sort.mergeSort(vec);
	sort.quickSort(vec);

	if(sort.isSorted(vec))
		for(auto x: vec)
			cout<<x<<endl;
	cout<<"end"<<endl;
	return 0;
}
