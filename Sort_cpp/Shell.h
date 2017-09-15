#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Shell
{
public:
	Shell(vector<T> &_vec): vec(_vec){}
	void sort();
	void sort(vector<T> &vec);
	bool isSorted(vector<T> &vec);
private:
	void exch(vector<T>& vec, int i, int j);

private:
	vector<T> &vec;
};
