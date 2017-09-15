#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#define SIZE 10000
#define LEFT(n) (n*2+1)
#define RIGHT(n) (LEFT(n)+ 1)
#define PARENT(n) (n>>1)
using namespace std;

void insertSort(vector<int>& vec);
void selecteSort(vector<int>& vec);
void mergeSort(vector<int>& vec);
void heapSort(vector<int>& vec);
void quickSort(vector<int>& vec);

void countingSort(vector<int>& vec);
void radixSort(vector<int>& vec);

void exchange(int &a, int &b);
void sink(vector<int>& vec, int i, int n);
int partition(vector<int>& vec, int lo, int hi);

int main()
{
    ifstream in("random.txt");
    ifstream sorted("sorted.txt");

    int num, i = 0;
    vector<int> vec;

    while(in >> num)
    {
        vec.push_back(num);
    }

    countingSort(vec);

    while(sorted >> num)
    {
        cout << "TESTING........" << num << endl;
        int test = vec[i++];
        if(num == test)
        {
            continue;
        }
        else
        {
            cout << "WRONG ANSWER" << endl;
            cout << "ERROR POSITION: " << num << endl;
            exit(0);
        }
    }
    cout << "PASSED" << endl;

    return 0;
}

void exchange(int &a, int &b)
{
    auto temp = a;
    a = b;
    b = temp;
}

void insertSort(vector<int>& vec, int lo, int hi)
{
    for(int i = lo+1; i != hi+1; ++i)
    {
        for(int j = i; j > lo && vec[j] < vec[j-1]; --j)
        {
            exchange(vec[j], vec[j-1]);
        }
    }
}

void insertSort(vector<int>& vec)
{
    insertSort(vec, 0, vec.size()-1);
}

void selecteSort(vector<int>& vec)
{
    int size = vec.size();

    for(int i = 0; i != size-1; ++i)
    {
        int min = i;
        for(int j = i+1; j != size; ++j)
        {
            if(vec[j] < vec[min])
            {
                min = j;
            }
        }
        exchange(vec[min], vec[i]);
    }
}

void merge(vector<int>& vec, vector<int>& vecCopy, int lo, int mid, int hi)
{
    for(int i = lo; i <= hi; ++i)
        vecCopy[i] = vec[i];

    int i = lo, j = mid+1;
    for(int k = lo; k <= hi; ++k)
    {
        if(i > mid)
            vec[k] = vecCopy[j++];
        else if(j > hi)
            vec[k] = vecCopy[i++];
        else if(vecCopy[i] < vecCopy[j])
            vec[k] = vecCopy[i++];
        else
            vec[k] = vecCopy[j++];
    }
}

void mergeSort(vector<int>& vec, vector<int>& vecCopy, int lo, int hi)
{
    int n = hi-lo+1;
    if(n <= 10)
    {
        insertSort(vec, lo, hi);
        return;
    }
    if(lo >= hi)
        return;

    int mid = lo + (hi-lo)/2;
    mergeSort(vec, vecCopy, lo, mid);
    mergeSort(vec, vecCopy, mid+1, hi);
    merge(vec, vecCopy, lo, mid, hi);
}

void mergeSort(vector<int>& vec)
{
    vector<int> vecCopy(vec);
    mergeSort(vec, vecCopy, 0, vec.size()-1);
}

void sink(vector<int>& vec, int i, int n)
{
    while(i*2 < n)
    {
        int child = 2*i+1;
        if(child+1 < n && vec[child] < vec[child+1])
            ++child;
        if(vec[child] < vec[i])
            break;
        exchange(vec[child], vec[i]);
        i = child;
    }
}

void heapSort(vector<int>& vec)
{
    int len = vec.size();
    for(int i = len/2; i >= 0; --i)
        sink(vec, i, len);
    for(int i = len-1; i > 0; --i)
    {
        exchange(vec[i], vec[0]);
        sink(vec, 0, i-1);
    }
}

void quickSort(vector<int>& vec, int lo ,int hi)
{
    if(lo < hi)
    {
        int par = partition(vec, lo, hi);
        quickSort(vec, lo, par-1);
        quickSort(vec, par+1, hi);
    }
}

void threeWayQuickSort(vector<int>& vec, int lo, int hi)
{
    if(hi <= lo) return;
    int lt = lo, i = lo+1, gt = hi;
    int v = vec[lo];

    while(i <= gt)
    {
        int cmp = vec[i] - v;
        if(cmp < 0) exchange(vec[lt++], vec[i++]);
        else if(cmp > 0) exchange(vec[i], vec[gt--]);
        else ++i;
    }
    threeWayQuickSort(vec, lo, lt-1);
    threeWayQuickSort(vec, gt+1, hi);
}

void quickSort(vector<int>& vec)
{
    threeWayQuickSort(vec, 0, vec.size()-1);
//    quickSort(vec, 0, vec.size()-1);
}

int partition(vector<int>& vec, int lo, int hi)
{
    int i = lo-1, j = hi, x = vec[hi];
    while(1)
    {
        while(vec[++i] < x)
            if(i == hi) break;
        while(vec[--j] > x)
            if(j == lo) break;
        if(i < j)
            exchange(vec[i], vec[j]);
        else
            break;
    }
    exchange(vec[i], vec[hi]);
    return i;
}

//计数排序


void countingSort(vector<int>& vec, vector<int>& aux, int k)
{
	int N = vec.size();
	vector<int> count(k+1, 0); //记录的是这个数应该的起始位置
	for(int i = 0; i < N; ++i)
		count[vec[i]+1]++;
	for(int d = 0; d < k; ++d)
		count[d+1] += count[d];
	for(int i = 0; i < N; ++i)
		aux[count[vec[i]]++] = vec[i];
}

void countingSort(vector<int>& vec)
{
    int k = 10000;
    vector<int> aux(vec.size(), 0);
    countingSort(vec, aux, k);
    for(int i = 0; i < vec.size(); ++i)
        vec[i] = aux[i];
}

void radixSort(vector<int>& vec, int d) //对５位数的整数进行排序
{
    for(int i = d-1; i >= 0; --i)
    {

    }
}

void radixSort(vector<int>& vec)
{
    radixSort(vec, 5);
}
