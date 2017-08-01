#include "LSD.h"

int main()
{
	ifstream in("words3.txt");
	string str;
	vector<string> strVec;
	while(in >> str)
		strVec.push_back(str);

	LSD lsd;
	lsd.sort(strVec, 3);

	for(auto x: strVec)
		cout << x << endl;

	return 0;
}
