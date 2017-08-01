#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class LSD
{
public:
	void sort(vector<string> &a, int W) //通过前W个字符进行排序
	{
		int N = a.size();
		int R = 256;
		vector<string> aux = vector<string>(N, "");

		for(int d = W-1; d >= 0; --d)
		{
			vector<int> count(R+1, 0);
			for(int i = 0; i < N; ++i)
				count[a[i][d]+1]++;
			for(int r = 0; r < R; ++r)
				count[r+1] += count[r];
			for(int i = 0; i < N; ++i)
				aux[count[a[i][d]]++] = a[i];
			for(int i = 0; i < N; ++i)
				a[i] = aux[i];
		}
	}
};
