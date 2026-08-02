class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (char c : s) {
            if (c == '*') {

                if (res != "") {
                    res.pop_back();
                }
            } else if (c == '#') {
                if (res.size() != 0) {
                    res += res;
                }
            } else if (c == '%') {
                for (int i = 0; i < res.size() / 2; i++) {
                    char t = res[i];
                    res[i] = res[res.size() - i - 1];
                    res[res.size() - i - 1] = t;
                }
            } else {
                res += c;
            }
        }
        return res;
    }
};