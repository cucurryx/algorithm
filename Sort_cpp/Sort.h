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
	bool isSorted(vector<T> &vec);

	void selecteSort(T *array, int n);
	void shellSort(T *array, int n);
	void insertSort(T *array, int n);
	void mergeSort(T *array, int n);
	void quickSort(T *array, int n);
	bool isSorted(T *array, int n);

private:
	void mergeSort(vector<T> &vec, int lo, int hi);
	void merge(vector<T> &vec, int lo, int mi, int hi);
	void exch(vector<T> &vec, int i, int j);
	bool less(vector<T> &vec, int i, int j);

	void mergeSort(T* array, int lo, int hi);
	void merge(T* array, int lo, int mi, int hi);
	void exch(T* array, int i, int j);
	bool less(T *array, int i, int j);

private:
	vector<T> vecCopy;
	T *arrayCopy;
};

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

}

template <typename T>
bool Sort<T>::isSorted(vector<T> &vec)
{
	for(int i = 0; i < vec.size()-1; ++i)
		if(less(vec, i+1, i))
			return false;
	return true;
}

//T*
template <typename T>
void Sort<T>::selecteSort(T *array, int n)
{
	for(int i = 0; i < n-1; ++i)
		for(int j = i+1; j < n; ++j)
			if(less(array, j, i))
				exch(array, j, i);
}

template <typename T>
void Sort<T>::shellSort(T *array, int n)
{
	int h = 1;
	while(h < n/3)
		h = h*3 + 1;
	while(h > 0)
	{
		for(int i = h; i < n; ++i)
			for(int j = i; j >= h && less(array, j, j-h); j -= h)
				exch(array, j, j-h);
		h /= 3;
	}
}

template <typename T>
void Sort<T>::insertSort(T *array, int n)
{
	for(int i = 1; i < n; ++i)
		for(int j = i; j > 0 && less(array, j, j-1); --j)
			exch(array, i, j);
}

template <typename T>
void Sort<T>::mergeSort(T *array, int n)
{
	T* arrayCopy = new int[n+1];
	for(int i = 0; i < n; ++i)
		arrayCopy[i] = array[i];
	mergeSort(array, 0, n-1);
	delete arrayCopy;
}

template <typename T>
void Sort<T>::mergeSort(T* array, int lo, int hi)
{
	if(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		mergeSort(array, lo, mid);
		mergeSort(array, mid+1, hi);
		merge(array, lo, mid, hi);
	}
}

template <typename T>
void Sort<T>::merge(T* array, int lo, int mid, int hi)
{
	int i = lo;
	int j = mid+1;
	for(int k = lo; k <= hi; ++k)
		if(i > mid)
			array[k] = arrayCopy[j++];
		else if(j > hi)
			array[k] = arrayCopy[i++];
		else if(less(array, i, j))
			array[k] = arrayCopy[i++];
		else
			array[k] = arrayCopy[j++];
}

template <typename T>
void Sort<T>::quickSort(T *array, int n)
{

}

template <typename T>
bool Sort<T>::isSorted(T *array, int n)
{
	for(int i = 0; i < n-1; ++i)
		if(less(array, n+1, n))
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
void Sort<T>::exch(T* array, int i, int j)
{
	T tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

template <typename T>
bool Sort<T>::less(vector<T> &vec, int i, int j)
{
	return vec[i] < vec[j];
}

template <typename T>
bool Sort<T>::less(T *array, int i, int j)
{
	return array[i] < array[j];
}
