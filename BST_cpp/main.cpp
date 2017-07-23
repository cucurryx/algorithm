#include "BST.h"

int main()
{
	BST<int, int> tree;

	for(int i = 0; i < 100; ++i)
		tree.put(i, i);
	tree.deleteMin();
	tree.deleteMax();
	cout<<tree.min()<<" "<<tree.max()<<endl;
	cout<<tree.size()<<endl;

	for(int i = 1; i < 90; ++i)
		tree.erase(i);
	cout<<tree.min()<<" "<<tree.max()<<endl;
	cout<<tree.size()<<endl;

	return 0;
}
