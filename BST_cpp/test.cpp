#include "AVLTree.h"

int main()
{
	AVLTree tree;

	for(int i = 0; i < 100; ++i)
	{
		tree.insert(i);
		tree.insert(-i);
		tree.erase(i);

	}

	cout << tree.size() << endl;

	return 0;
}
