#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

class MSD
{
public:
	void sort(vector<string> &vec)
	{
		int N = vec.size();
		aux = vector<string>(N, "");
		sort(vec, 0, N-1, 0);
	}

private:
	void sort(vector<string> &vec, int lo, int hi, int d)
	{
		if(hi <= lo + M)
		{
			std::sort(vec.begin()+lo, vec.begin()+hi+1);
			return ;
		}
		vector<int> count(R+2, 0);
		for(int i = lo; i <= hi; ++i)
			count[vec[i][d]+2]++;
		for(int r = 0; r < R+1; ++r)
			count[r+1] += count[r];
		for(int i = lo; i <= hi; ++i)
			aux[count[vec[i][d]+1]++] = vec[i];
		for(int i = lo; i <= hi; ++i)
			vec[i] = aux[i-lo];
		for(int r = 0; r < R; ++r)
			sort(vec, lo+count[r], lo+count[r+1]-1, d+1);
	}

private:
	int R = 256;
	int M = 3; //小数组的切换阀值
	vector<string> aux;
};
