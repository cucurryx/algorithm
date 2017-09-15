#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Sort
{
public:
	void selecteSort(vector<T> &vec);
	void shellSort(vector<T> &vec);
	void insertSort(vector<T> &vec);
	void mergeSort(vector<T> &vec);
	void quickSort(vector<T> &vec);
	void heapSort(vector<T> &vec);
	bool isSorted(vector<T> &vec);

private:
	void mergeSort(vector<T> &vec, int lo, int hi);
	void merge(vector<T> &vec, int lo, int mi, int hi);
	void quickSortThreeWay(vector<T> &vec, int lo, int hi);
	void quickSort(vector<T> &vec, int lo, int hi);
	int partition(vector<T> &vec, int lo, int hi);
	void exch(vector<T> &vec, int i, int j);
	bool less(vector<T> &vec, int i, int j);
	int compare(vector<T> &vec, int i, int j);
	void sink(vector<T> &vec, int i, int n);
	void swim(vector<T> &vec, int i);
private:
	vector<T> vecCopy;
};
