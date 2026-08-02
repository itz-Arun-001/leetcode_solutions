class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, s2;
        for (char a : s) {
            if (a >= 'a' && a <= 'z') {

                s1.push_back(a);
            } else {
                if (s1 != "")
                    s1.pop_back();
            }
        }
        for (char a : t) {
            if (a >= 'a' && a <= 'z') {
                s2.push_back(a);
            } else {
                if (s2 != "")
                    s2.pop_back();
            }
        }
        return (s1 == s2) ? true : false;
    }
};