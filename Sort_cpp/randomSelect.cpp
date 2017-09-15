#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const int SIZE = 10000;

int randomizedSelect(vector<int>& vec, int lo, int hi, int i);
int partition(vector<int>& vec, int lo, int hi);
void exchange(int &a, int &b);

int main()
{
    ifstream in("random.txt");
    ifstream sorted("sorted.txt");

    vector<int> vec;
    int num;

    while(in >> num)
        vec.push_back(num);

    for(int i = 0; i != SIZE; ++i)
    {
        sorted >> num;
        if(randomizedSelect(vec, 0, SIZE-1, i) == num)
            cout << "TESTING " << i << endl;
        else
            cout << "ERROR " << i << endl;
    }
    cout << "PASSED" << endl;

    return 0;
}

int randomizedSelect(vector<int>& vec, int lo, int hi, int i)
{
    if(hi == lo)
        return vec[lo];

    int par = partition(vec, lo, hi);
    int k = par-lo+1;

    if(k == i)
        return vec[par];
    else if(k < i)
        return randomizedSelect(vec, par+1, hi, i-k);
    else
        return randomizedSelect(vec, lo, par-1, i);
}

int partition(vector<int>& vec, int lo, int hi)
{
    int lt = lo, i = lo+1, gt = hi;
    int v = vec[lo];

    while(i <= gt)
    {
        int cmp = vec[i] - v;
        if(cmp < 0) exchange(vec[lt++], vec[i++]);
        else if(cmp > 0) exchange(vec[i], vec[gt--]);
        else ++i;
    }
    
    return i;
}

void exchange(int& a, int& b)
{
    auto x = a;
    a = b;
    b = x;
}
