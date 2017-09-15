#include "Sort.h"
template <typename T>
void Sort<T>::selecteSort(vector<T> &vec)
{
	int n = vec.size();
	for(int i = 0; i < n-1; ++i)
		for(int j = i+1; j < n; ++j)
			if(less(vec, j, i))
				exch(vec, i, j);
}

//vector<T>
template <typename T>
void Sort<T>::shellSort(vector<T> &vec)
{
	int n = vec.size();
	int h = 1;
	while(h < n/3)
		h = 3*h + 1;
	while(h >= 1)
	{
		for(int i = h; i < n; ++i)
			for(int j = i; j >= h && less(vec, j, j-h); j-=h)
				exch(vec, j, j-h);
		h /= 3;
	}
}

template <typename T>
void Sort<T>::insertSort(vector<T> &vec)
{
	int n = vec.size();
	for(int i = 1; i < n; ++i)
		for(int j = i; j > 0 && less(vec, j, j-1); --j)
			exch(vec, j, j-1);
}

template <typename T>
void Sort<T>::mergeSort(vector<T> &vec)
{
	auto begin = vec.begin();
	while(begin != vec.end())
		vecCopy.push_back(*begin++);
	mergeSort(vec, 0, vec.size()-1);
}

template <typename T>
void Sort<T>::mergeSort(vector<T>& vec, int lo, int hi)
{
	if(lo < hi)
	{
		int mid = lo + (hi- lo)/2;
		mergeSort(vec, lo, mid);
		mergeSort(vec, mid+1, hi);
		if(!less(vec, mid, mid+1)) //跳过有序数组的merge
			merge(vec, lo, mid, hi);
	}
}

template <typename T>
void Sort<T>::merge(vector<T> &vec, int lo, int mid, int hi)
{
	int i = lo;
	int j = mid+1;

	for(int k = lo; k <= hi; ++k)
		vecCopy[k] = vec[k];
	for(int k = lo; k <= hi; ++k)
		if(i > mid)
			vec[k] = vecCopy[j++];
		else if(j > hi)
			vec[k] = vecCopy[i++];
		else if(less(vecCopy, i, j))
			vec[k] = vecCopy[i++];
		else
			vec[k] = vecCopy[j++];
}

template <typename T>
void Sort<T>::quickSort(vector<T> &vec)
{
	//quickSort(vec, 0, vec.size()-1);
	quickSortThreeWay(vec, 0, vec.size()-1);
}

template <typename T>
void Sort<T>::quickSort(vector<T> &vec, int lo, int hi)
{
	if(lo >= hi)
		return;
	if(lo >= hi - 10)
	{
		insertSort(vec);
		return;
	}
	int j = partition(vec, lo, hi);
	quickSort(vec, lo, j-1);
	quickSort(vec, j+1, hi);
}

template <typename T>
int Sort<T>::partition(vector<T> &vec, int lo, int hi)
{
	int i = lo, j = hi+1;
	T v = vec[lo];
	while(true)
	{
		while(less(vec, ++i, lo))
			if(i == hi) break;
		while(less(vec, lo, --j))
			if(j == lo) break;
		if(i >= j) 	break;
		exch(vec, i, j);
	}
	exch(vec, lo, j);
	return j;
}

/*优化quicksort，对重复元素的处理更快*/
template <typename T>
void Sort<T>::quickSortThreeWay(vector<T> &vec, int lo, int hi)
{
	if(lo >= hi) return;
	int lt = lo, i = lo+1, gt = hi;
	T v = vec[lo];
	while(i <= gt)
	{
		if(vec[i] < v)
			exch(vec, i++, lt++);
		else if(vec[i] > v)
			exch(vec, i, gt--);
		else
			i++;
	}
	quickSortThreeWay(vec, lo, lt-1);
	quickSortThreeWay(vec, gt+1, hi);
}

template <typename T>
void Sort<T>::heapSort(vector<T> &vec)
{
	int n = vec.size();
	for(int i = n/2; i >= 0; --i)
		sink(vec, i, n);
	for(int i = n-1; i > 0; --i)
	{
		exch(vec, 0, i);
		sink(vec, 0, i-1);
	}
}

template <typename T>
bool Sort<T>::isSorted(vector<T> &vec)
{
	for(int i = 0; i < vec.size()-1; ++i)
		if(less(vec, i+1, i))
			return false;
	return true;
}


//private functions
template <typename T>
void Sort<T>::exch(vector<T> &vec, int i, int j)
{
	T tmp = vec[i];
	vec[i] = vec[j];
	vec[j] = tmp;
}

template <typename T>
bool Sort<T>::less(vector<T> &vec, int i, int j)
{
	return vec[i] < vec[j];
}

template <typename T>
int Sort<T>::compare(vector<T> &vec, int i, int j)
{
	if(vec[i] < vec[j])
		return -1;
	else if(vec[i] > vec[j])
		return 1;
	else
		return 0;
}

template <typename T>
void Sort<T>::sink(vector<T> &vec, int i, int n)
{
	while(2*i < n)
	{
		int child = 2*i + 1;
		if(child+1 < n && less(vec, child, child+1))
			++child;
		if(!less(vec, i, child))
			break;
		exch(vec, child, i);
		i = child;
	}
}

template <typename T>
void Sort<T>::swim(vector<T> &vec, int i)
{
	while(less(vec, i/2, i) && i > 0)
	{
		exch(vec, i, i/2);
		i /= 2;
	}
}
