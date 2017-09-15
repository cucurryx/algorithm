#include "AVLTree.h"

int main()
{
	AVLTree tree;

	for(int i = 1; i != 100; ++i)
	{
		tree.insert(i);
		tree.insert(-i);
		tree.erase(i-10);
	}
	tree.midOrder();

	cout << tree.size() << endl;

	return 0;
}
