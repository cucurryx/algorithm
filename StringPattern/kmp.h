#include <vector>
#include <string>

using std::vector;
using std::string;

class Kmp {
public:
    Kmp (string _pat):
        pat(_pat) {
        auto row = 256;
        auto col = pat.size();
        dfa = vector<vector<int>>(row, vector<int>(col, 0));
        dfa[int(pat[0])][0] = 1;
        
        for (int x = 0, j = 1; j < col; ++j) {
            for (int c = 0; c < row; ++c) {
                dfa[c][j] = dfa[c][x];
            }
            dfa[pat[j]][j] = j + 1;
            x = dfa[pat[j]][x];
        }
    }

    int search(const string &txt) {
        auto m = pat.size();
        auto n = txt.size();

        auto it_pat = 0;
        auto it_txt = 0;
        while (it_pat < m && it_txt < n) {
            it_pat = dfa[txt[it_txt]][it_pat];
            ++it_txt;
        }

        if (it_pat == m) 
            return it_txt - m;
        return -1;
    }

private:
    vector<vector<int>> dfa;
    string pat;
};