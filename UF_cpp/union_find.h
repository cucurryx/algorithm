//
// Created by xvvx on 17-7-19.
//


#ifndef TREE_JAVA_UNION_FIND_H
#define TREE_JAVA_UNION_FIND_H

#include <vector>
using namespace std;

// quick_find and quick_union

class union_find
{
public:
    union_find(int N);
    void _union(int p, int q);
    int find(int p);
    bool connected(int p, int q);
    int count();

private:
    vector<int> vec;
    int _count; //连通分量的数量
};

union_find::union_find(int N)
{
    for(int i = 0; i < N; ++i)
        vec.push_back(i);
	_count = N;
}

// quick_find
/*
void union_find::_union(int p, int q)
{
    if(find(p) != find(q))
    {
        int p_num = vec[p], q_num = vec[q];
        for(auto &x: vec)
        {
            if(x == p_num)
                x = q_num;
        }
        --_count;
    }
}

int union_find::find(int p)
{
    return vec[p];
}
*/
// quick_union
void union_find::_union(int p, int q)
{
	int proot = find(p);
	int qroot = find(q);
	if(proot != qroot)
	{
		vec[proot] = qroot;
		--_count;
	}
}

int union_find::find(int p)
{
	while(vec[p] != p)
		p = vec[p];
	return p;
}

bool union_find::connected(int p, int q)
{
    return find(p) == find(q);
}

int union_find::count()
{
    return _count;
}



#endif //TREE_JAVA_UNION_FIND_H
