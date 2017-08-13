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

void AVLTree::insert(valueType val)
{
	if(find(val, root) == nullptr)
	{
		root = insert(val, root);
	}
}

void AVLTree::erase(valueType val)
{
	if(find(val, root) != nullptr)
	{
		root = erase(val, root);
	}
}

int AVLTree::size()
{
	return size(root);
}

bool AVLTree::empty()
{
	return size(root) == 0;
}

bool AVLTree::find(valueType val)
{
	return find(val, root) != nullptr;
}

TreeNode* AVLTree::insert(valueType val, TreeNode* node)
{
	if(node == nullptr)
		return new TreeNode(val);
	if(val < node->val)
		node->left = insert(val, node->left);
	else if(val > node->val)
		node->right = insert(val, node->right);
	return node;
}

TreeNode* AVLTree::erase(valueType val, TreeNode* node)
{
	if(node->val > val)
		node->left = erase(val, node->left);
	else if(node->val < val)
		node->right = erase(val, node->right);
	else if(node->left && node->right)
	{
		node->val = min(node->right);
		node->right = erase(node->val, node->right);
	}
	else
	{
		if(node->left != nullptr)
		{
			TreeNode* pnode = node;
			node = node->left;
			delete pnode;
		}
		else if(node->right != nullptr)
		{
			TreeNode* pnode = node;
			node = node->right;
			delete pnode;
		}
		else
		{
			node = nullptr;
		}
	}
}

TreeNode* AVLTree::find(valueType val, TreeNode* node)
{
	if(node == nullptr)
		return nullptr;
	if(node->val > val)
		return find(val, node->left);
	else if(node->val < val)
		return find(val, node->right);
	else
		return node;
}

int AVLTree::size(TreeNode* node)
{
	if(node == nullptr)
		return 0;
	return size(node->left)+size(node->right)+1;
}

valueType AVLTree::min(TreeNode* node)
{
	while(node->left != nullptr)
		node = node->left;
	return node->val;
}

void AVLTree::preOrder()
{
	preOrder(root);
}

void AVLTree::midOrder()
{
	midOrder(root);
}

void AVLTree::preOrder(TreeNode* node)
{
	if(node == nullptr)
		return;
	cout << node->val << " ";
	preOrder(node->left);
	preOrder(node->right);
}

void AVLTree::midOrder(TreeNode* node)
{
	if(node == nullptr)
		return;
	midOrder(node->left);
	cout << node->val << " ";
	midOrder(node->right);
}
