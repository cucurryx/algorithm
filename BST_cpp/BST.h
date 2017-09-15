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
