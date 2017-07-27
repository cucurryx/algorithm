#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
	Graph(int _v): v(_v), e(0), adj(_v, vector<int>()){}
	
private:
	int v;
	int e;
	vector<vector<int>> adj;
};
