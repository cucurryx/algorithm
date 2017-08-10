#include <iostream>
using namespace std;

union u
{
	short int a;
	char b;
};

bool isBigEndian()
{
	union u un;
	un.a = 0x1122;
	return un.b == 0x11;
}

int main()
{
	if(isBigEndian())
		cout << "This computer is big endian" << endl;
	else
		cout << "This computer is small endian" << endl;

	return 0;
}
