#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define SIZE 10000
using namespace std;

int countReverse(vector<int>& vec);
int countReverse(vector<int>& vec, int lo, int hi);
int count(vector<int>& vec, int lo, int mid, int hi);
void insertSort(vector<int>& vec, int lo, int hi);

int ans = 0;

int main()
{
    ifstream in("random.txt");

    vector<int> vec;
    int num;

    while(in >> num)
        vec.push_back(num);

    vector<int> vecTwo(vec);
    insertSort(vecTwo, 0, vec.size()-1);

    cout << "MY   ANSWER: " << countReverse(vec) << endl;
    cout << "TRUE ANSWER: " << ans << endl;

    return 0;
}

int countReverse(vector<int>& vec)
{
    return countReverse(vec, 0, vec.size()-1);
}

int countReverse(vector<int>& vec, int lo, int hi)
{
    if(lo < hi)
    {
        int mid = lo + (hi-lo)/2;
        int pre = countReverse(vec, lo, mid);
        int post = countReverse(vec, mid+1, hi);
        return pre + post + count(vec, lo, mid, hi);
    }
    return 0;
}

/****** buggy ******/

int count(vector<int>& vec, int lo, int mid, int hi)
{
    vector<int> vecCopy;
    for(int i = lo; i <= hi; ++i)
        vecCopy.push_back(vec[i]);

    int i = lo, j = mid+1, cnt = 0;
    bool counted = false;

    for(int k = lo; k <= hi; ++k)
    {
        if(counted == false && vecCopy[i-lo] > vecCopy[j-lo])
        {
            cnt += hi-i+1;
            counted = true;
        }
        if(vecCopy[i-lo] <= vecCopy[j-lo])
        {
            vec[k] = vecCopy[i-lo];
            ++i;
        }
        else
        {
            vec[k] = vecCopy[j-lo];
            ++j;
            counted = false;
        }
    }
    return cnt;
}

/*** count reverse by insertSort***/

void exchange(int &a, int &b)
{
    ++ans;
    auto x = a;
    a = b;
    b = x;
}

void insertSort(vector<int>& vec, int lo, int hi)
{
    for(int i = lo+1; i != hi+1; ++i)
    {
        for(int j = i; j > 0 && vec[j] < vec[j-1]; --j)
        {
            exchange(vec[j], vec[j-1]);
        }
    }
}
