#include "Shell.h"

template <typename T>
void Shell<T>::sort()
{
	int N = vec.size();
	int h = 1;
	while(h < N/3)
		h = 3*h + 1;
	while(h >= 1)
	{
		for(int i = h; i < N; ++i)
		{
			for(int j = i; j >= h && vec[j] < vec[j-h]; j-=h)
				exch(vec, j, j-h);
		}
		h /= 3;
	}
}

template <typename T>
void Shell<T>::sort(vector<T> &_vec)
{
	vec = _vec;
	sort();
}

template <typename T>
bool Shell<T>::isSorted(vector<T>& vec)
{
	for(int i = 0; i < vec.size()-1; ++i)
		if(vec[i] > vec[i+1])
			return false;
	return true;
}

template <typename T>
void Shell<T>::exch(vector<T> &vec, int i, int j)
{
	T tmp = vec[i];
	vec[i] = vec[j];
	vec[j] = tmp;
}
