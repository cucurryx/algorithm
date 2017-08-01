#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

const int null = INT_MAX;
const int R = 256;

class Node
{
public:
	Node(): val(null), next(vector<Node*>(R, NULL)){}
public:
	int val;
	vector<Node*> next;
};

class StringST
{
public:
	StringST(){ root = new Node(); }

public:
	int size() { return size(root); }
	bool contains(string key) { return get(root, key, 0) != NULL; }
	bool isEmpty() { return size(root) == 0; }

	string longestPrefixOf(string s)
	{
		int length = search(root, s, 0, 0);
		return string(s, 0, length);
	}

	vector<string> keysWithPrefix(string pre)
	{
		vector<string> vec;
		collect(get(root, pre, 0), pre, vec);
		return vec;
	}

	vector<string> keysThatMatch(string pat) // '.'代表任意字符
	{
		vector<string> vec;
		collect(root, "", pat, vec);
		return vec;
	}

	vector<string> keys()
	{
		return keysWithPrefix("");
	}

	int get(string key)
	{
		Node *x = get(root, key, 0);
		if(x == NULL)
			return null;
		return x->val;
	}

	void put(string key, int val)
	{
		root = put(root, key, val, 0);
	}

	void deleteKey(string key)
	{
		root = deleteKey(root, key, 0);
	}

private:
	Node* get(Node* x, string key, int d)
	{
		if(x == NULL)
			return NULL;
		else if(key.size() == d)
			return x;
		return get(x->next[key[d]], key, d+1);
	}

	Node* put(Node* x, string key, int val, int d)
	{
		if(x == NULL)
			x = new Node();
		if(d == key.size())
		{
			x->val = val;
			return x;
		}
		x->next[key[d]] = put(x->next[key[d]], key, val, d+1);
		return x;
	}

	int size(Node* x)
	{
		if(x == NULL)
			return 0;
		int cnt = 0;
		if(x->val != null)
			++cnt;
		for(int c = 0; c < R; ++c)
			cnt += size(x->next[c]);
		return cnt;
	}

	Node* deleteKey(Node* x, string key, int d)
	{
		if(x == NULL)
			return NULL;
		if(d == key.size())
			x->val = null;
		else
			x->next[key[d]] = deleteKey(x->next[key[d]], key, d+1);

		if(x->val != null)
			return x;
		for(int c = 0; c < R; ++c)
			if(x->next[c] != NULL)
				return x;
		return NULL;
	}

	void collect(Node* x, string pre, vector<string>& vec)
	{
		if(x == NULL)
			return;
		if(x->val != null)
			vec.push_back(pre);
		for(int c = 0; c < R; ++c)
			collect(x->next[c], pre + char(c), vec);
	}

	void collect(Node* x, string pre, string pat, vector<string>& vec)
	{
		int d = pre.size();
		if(x == NULL)
			return;
		if(d == pat.size() && x->val != null)
			vec.push_back(pre);
		if(d == pat.size())
			return;

		for(int i = 0; i < R; ++i)
			if(pat[d] == '.' || pat[d] == i)
				collect(x->next[i], pre + char(i), pat, vec);
	}

	int search(Node* x, string s, int d, int length)
	{
		if(x == NULL)
			return length;
		if(x->val != null)
			length = d;
		if(d == s.size())
			return length;
		return search(x->next[s[d]], s, d+1, length);
	}
	
private:
	Node *root;
};
