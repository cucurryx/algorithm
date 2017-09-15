#include <iostream>
using namespace std;

typedef int valueType;

class TreeNode
{
public:
	TreeNode(valueType v):
		left(nullptr),
		right(nullptr),
		val(v) {}

public:
	TreeNode* left;
	TreeNode* right;
	valueType val;
};

class AVLTree
{
public:
	AVLTree(): root(nullptr){}

	void insert(valueType val);
	void erase(valueType val);
	int size();
	bool empty();
	bool find(valueType val);
	valueType min();

	void preOrder();
	void midOrder();

private:
	TreeNode* insert(valueType val, TreeNode* node);
	TreeNode* erase(valueType val, TreeNode* node);
	TreeNode* find(valueType val, TreeNode* node);
	int size(TreeNode* node);
	valueType min(TreeNode* node);

	void preOrder(TreeNode* node);
	void midOrder(TreeNode* node);

private:
	TreeNode* root;
};
