/*class Solution {
public:
    char processStr(string s, long long k) {
        string res = "";
        for (char a : s) {
            if (a == '*') {
                if (res != "") {
                    res.pop_back();
                }
            } else if (a == '#') {
                if (res != "") {
                    res += res;
                }

            } else if (a == '%') {
                for (long long i = 0; i < res.size() / 2; i++) {
                    char c=res[i];
                    res[i] = res[res.size() - 1 - i];
                    res[res.size()-i-1]=c;
                }
            }
            else{
                res+=a;
            }

        }
        return (k<res.size())?res[k]:'.';
    }
};*/
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);

        long long curLen = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == '*') {
                if (curLen > 0)
                    curLen--;
            }
            else if (ch == '#') {
                curLen *= 2;
            }
            else if (ch == '%') {
                // length unchanged
            }
            else {
                curLen++;
            }

            len[i] = curLen;

            // Prevent overflow
            if (curLen > (long long)4e18)
                curLen = (long long)4e18;
        }

        if (k >= len[n - 1])
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            long long prevLen = (i == 0) ? 0 : len[i - 1];

            if ('a' <= ch && ch <= 'z') {
                if (k == prevLen)
                    return ch;
            }
            else if (ch == '#') {
                if (prevLen > 0 && k >= prevLen)
                    k -= prevLen;
            }
            else if (ch == '%') {
                if (len[i] > 0)
                    k = len[i] - 1 - k;
            }
            // '*' needs no change to k
        }

        return '.';
    }
};