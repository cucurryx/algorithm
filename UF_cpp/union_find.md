# union_find数据结构

#### union_find迄今还没有找到能够保证在常数时间内完成的算法，最快的也只是加权quick_union算法(此处算法3)的对数时间内完成。####



union_find的实现有三种方法，分别是：

- quick_find 这个方法是find常数时间，而union是平方级别的。该算法的实现就是，同一个集合的所有元素都指向同一个数。mark

- quick_union 这个方法是union常数时间，而find是最坏情形平方级别，quick_union在大部分情况比quick_find快，但是最坏情形十分糟糕。这个算法的实现是每个元素都有一个连接，指向connected的另一个元素，也可以指向自己，如果连接指向自己，那么这个元素就是根节点root。

- weighted_quick_union是最好的算法，他是对数级别的。因为这个算法多添加了记录每个树的大小的数组，来避免大树连接在小树的情况发生。该算法的find()函数和quick_union的一致，只是union()函数有所修改，来改进性能。

### quick_find算法
```
// quick_find
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
```


### quick_union算法
```
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
```


### weighted_quick_union算法
```

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

```


```
/****************测试结果 100w数据 200w连接**************
 *  quick_find| area: 999950  time: 0.593439s
 *  quick_union| area: 999950  time: 2.6e-05s
 *  weighted_quick_union| area: 999950  time: 3.1e-05s
 *****************************************************/
```
