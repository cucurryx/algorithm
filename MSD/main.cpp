#include "Quick3string.h"

int main()
{
	ifstream in("test.txt");
	vector<string> strVec;
	string str;
	while(in >> str)
		strVec.push_back(str);

	//MSD msd;
	//msd.sort(strVec);
	Quick3string qs;
	qs.sort(strVec);

	for(auto x: strVec)
		cout << x << endl;


	return 0;
}
