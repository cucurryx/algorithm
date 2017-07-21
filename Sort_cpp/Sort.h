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
	void exch(vector<T> &vec, int i, int j);
	void exch(T* array, int i, int j);
	bool less(vector<T> &vec, int i, int j);
	bool less(T *array, int i, int j);
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

}

template <typename T>
void Sort<T>::mergeSort(T *array, int n)
{

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
