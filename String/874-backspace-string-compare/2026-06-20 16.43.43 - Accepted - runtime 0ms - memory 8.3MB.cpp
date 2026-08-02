class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        while (i >= 0 || j >= 0) {
            int iskip = 0;
            while (i >= 0) {
                if (s[i] == '#') {
                    iskip++;
                    i--;
                } else if (iskip > 0) {
                    iskip--;
                    i--;
                } else
                    break;
            }
            int jskip = 0;
            while (j >= 0) {
                if (t[j] == '#') {
                    jskip++;
                    j--;
                } else if (jskip > 0) {
                    jskip--;
                    j--;
                } else
                    break;
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j])
                    return false;
            } else if (i >= 0 || j >= 0) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};

/*class Solution {
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
};*/
