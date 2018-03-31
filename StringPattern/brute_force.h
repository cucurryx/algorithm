#include <vector>
#include <string>

using std::vector;
using std::string;

class BruteForce {
public:
    BruteForce (string _pat):
        pat(_pat) { }

    int search(const string &txt) {
        int i = 0, j = 0;
        int m = pat.size();
        int n = txt.size();

        while (i < n - m && j < m) {
            for (j = 0; txt[i+j] == pat[j++]; ) {
                if (j == m) {
                    return i;
                }
            }
            ++i;
        }
        return -1;
    }

private:
    string pat;
};