#include <iostream>
#include <string>
using namespace std;

template <typename Key, typename Value>
class TreeNode
{
public:
	TreeNode(Key _key, Value _value, TreeNode* _left, TreeNode* _right):
	key(_key), value(_value), left(_left), right(_right){}
public:
	Key key;
	Value value;
	TreeNode *left, *right;
};

template <typename Key, typename Value>
class BST
{
public:
	BST(): root(NULL){}
	void put(Key key, Value val)
	{
		root = put(root, key, val);
	}

	Value get(Key key)
	{
		TreeNode<Key, Value>* node = root;
		if(contains(key))
			while(node != NULL)
				if(key < node->key)
					node = node->left;
				else if(key > node->key)
					node = node->right;
				else
					return node->value;
		else
			return static_cast<Key>(NULL);
	}

	void erase(Key key)
	{
		root = erase(root, key);
	}

	bool contains(Key key)
	{
		TreeNode<Key, Value>* node = root;
		while(node != NULL)
		{
			if(key < node->key)
				node = node->left;
			else if(key > node->key)
				node = node->right;
			else
				return true;
		}
		return false;
	}

	bool isEmpty()
	{
		return treeSize == 0;
	}

	int size()
	{
		return treeSize;
	}

	Key min()
	{
		TreeNode<Key, Value>* node = root;
		while(node->left != NULL)
			node = node->left;
		return node->key;
	}

	Key max()
	{
		TreeNode<Key, Value>* node = root;
		while(node->right != NULL)
			node = node->right;
		return node->key;
	}

	void deleteMin()
	{
		root = deleteMin(root);
	}

	void deleteMax()
	{
		root = deleteMax(root);
	}

private:
	TreeNode<Key, Value>* put(TreeNode<Key, Value>* node, Key key, Value value)
	{
		if(node == NULL)
		{
			++treeSize;
			return new TreeNode<Key, Value>(key, value, NULL, NULL);
		}
		if(key == node->key)
			node->value = value;
		else if(key < node->key)
			node->left = put(node->left, key, value);
		else if(key > node->key)
			node->right = put(node->right, key, value);
		return node;
	}

	TreeNode<Key, Value>* erase(TreeNode<Key, Value>* node, Key key)
	{
		if(node == NULL)
			return node;
		if(key < node->key)
			node->left = erase(node->left, key);
		else if(key > node->key)
			node->right = erase(node->right, key);
		else
		{
			--treeSize;
			if(node->left == NULL)
				return node->right;
			if(node->right == NULL)
				return node->left;
			TreeNode<Key, Value>* t = node;
			node->key = min(node->right);
			node->value = get(node->key);
			node->right = deleteMin(t->right);
			node->left = t->left;
		}
		return node;
	}

	Key min(TreeNode<Key, Value>* h)
	{
		TreeNode<Key, Value>* node = h;
		while(node->left != NULL)
			node = node->left;
		return node->key;
	}

	Key max(TreeNode<Key, Value>* h)
	{
		TreeNode<Key, Value>* node = h;
		while(node->right != NULL)
			node = node->right;
		return node->key;
	}

	TreeNode<Key, Value>* deleteMin(TreeNode<Key, Value>* node)
	{
		if(node->left == NULL)
		{
			--treeSize;
			return node->right;
		}
		node->left = deleteMin(node->left);
		return node;
	}

	TreeNode<Key, Value>* deleteMax(TreeNode<Key, Value>* node)
	{
		if(node->right == NULL)
		{
			--treeSize;
			return node->left;
		}
		node->right = deleteMax(node->right);
		return node;
	}
private:
	TreeNode<Key, Value>* root;
	int treeSize;
};
