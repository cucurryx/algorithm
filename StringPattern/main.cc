#include "kmp.h"
#include "brute_force.h"

#include <iostream>
#include <fstream>

using namespace std;


int main() {
    string pattern;
    string txt;

    pattern = "INDSLFJldsajflsadjfIADFNlNFLznocijlfndlfNSAOIFASLFDNSAL";

    cin >> txt;

    Kmp kmp(pattern);
    //BruteForce bf(pattern);

    cout << kmp.search(txt);
  //  cout << bf.search(txt);
}
