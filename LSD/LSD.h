#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//低位优先的字符串排序
class LSD
{
public:
	void sort(vector<string> &vec, int W)
	{
		int N = vec.size();
		int R = 256;

		for(int d = W-1; d >= 0; --d)
		{
			vector<int> count(R+1, 0);
			vector<string> aux(N, "");
			for(int i = 0; i < N; ++i)
				count[vec[i][d]+1]++;
			for(int d = 0; d < R; ++d)
				count[d+1] += count[d];
			for(int i = 0; i < N; ++i)
				aux[count[vec[i][d]]++] = vec[i];
			for(int i = 0; i < N; ++i)
				vec[i] = aux[i];
		}
	}
};
