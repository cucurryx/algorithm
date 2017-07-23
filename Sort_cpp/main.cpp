#include "Sort.h"
// sort(T*, int)
// sort(vector<T>&)

int main()
{
	Sort<int> sort;
	vector<int> vec;
	for(int i = 0; i != 11111; ++i)
	{
		auto num = static_cast<int>(rand()%1000);
		vec.push_back(num);
	}
	//sort.shellSort(vec);
	//sort.insertSort(vec);
	//sort.selecteSort(vec);
	//sort.mergeSort(vec)；
	sort.quickSort(vec);

	if(sort.isSorted(vec))
		for(auto x: vec)
			cout<<x<<endl;
	cout<< rand()%4 <<endl;
	return 0;
}
