#include "MSD.h"

int main()
{
	ifstream in("words.txt");
	vector<string> strVec;
	string str;
	while(in >> str)
		strVec.push_back(str);

	MSD msd;
	msd.sort(strVec);

	for(auto x: strVec)
		cout << x << endl;

	return 0;
}
