#include "MSD.h"

class Quick3string
{
public:
	void sort(vector<string> &vec)
	{
		sort(vec, 0, vec.size()-1, 0);
	}

private:
	int charAt(string s, int d)
	{
		if(d < s.size())
			return s[d];
		else
			return -1;
	}

	void sort(vector<string> &vec, int lo, int hi, int d)
	{
		if(hi <= lo) return;
		int lt = lo, gt = hi, mi = lo+1;
		int v = charAt(vec[lo], d);

		while(mi <= gt)
		{
			int t = charAt(vec[mi], d);
			if(t < v)
				exch(vec, mi++, lt++);
			else if(t > v)
				exch(vec, mi, gt--);
			else
				++mi;
		}

		sort(vec, lo, lt-1, d);
		if(v >= 0)
			sort(vec, lt, gt, d+1);
		sort(vec, gt+1, hi, d);
	}

	void exch(vector<string> &vec, int a, int b)
	{
		auto x = vec[a];
		vec[a] = vec[b];
		vec[b] = x;
	}
};
