#include <vector>
using namespace std;

class weighted_union_find
{
public:
	weighted_union_find(int n);
	void _union(int p, int q);
	int find(int p);
	bool connected(int p, int q);
	int count();

private:
	vector<int> vec;
	vector<int> size;
	int area_count;
};

weighted_union_find::weighted_union_find(int n)
{
	for(int i = 0; i < n; ++i)
	{
		vec.push_back(i);
		size.push_back(1);
	}
	area_count = n;
}

void weighted_union_find::_union(int p, int q)
{
	int proot = find(p);
	int qroot = find(q);
	if(proot != qroot)
	{
		if(size[proot] > size[qroot])
		{
			vec[qroot] = proot;
			size[proot] += size[qroot];
		}
		else
		{
			vec[proot] = qroot;
			size[qroot] += size[proot];
		}
		--area_count;
	}
}

int weighted_union_find::find(int p)
{
	while(vec[p] != p)
		p = vec[p];
	return p;
}

bool weighted_union_find::connected(int p, int q)
{
	return find(p) == find(q);
}

int weighted_union_find::count()
{
	return area_count;
}
