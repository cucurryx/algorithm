#include "StringST.h"

int main()
{
	ifstream in("words.txt");
	StringST strTree;

	string str;
	while(in >> str)
		strTree.put(str, str.size());

	if(strTree.contains("surely"))
		cout << strTree.get("surely") << endl;
	cout << strTree.size() << endl;

	cout << strTree.keysWithPrefix("a").size() << endl;
	for(auto x: strTree.keysWithPrefix(""))
		cout << x << endl;

	for(auto x: strTree.keysThatMatch(".;"))
		cout << x << endl;

	cout << "Test of longestPrefixOf:" << endl;
	cout << strTree.longestPrefixOf("youArePig") << endl;

	return 0;
}
