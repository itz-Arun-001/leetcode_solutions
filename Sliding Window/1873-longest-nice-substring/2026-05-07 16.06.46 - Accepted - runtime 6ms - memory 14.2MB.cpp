class Solution {
public:
    string divide(string s)
    {
        int n=s.size();
        if(n<2) return "";
        unordered_set<char> st;

        for (char c : s)
            st.insert(c);

        for (int i = 0; i < n; i++) {

            char c = s[i];

            if (st.count(tolower(c)) && st.count(toupper(c)))
                continue;

            string left = divide(s.substr(0, i));
            string right = divide(s.substr(i + 1));

            return left.size() >= right.size() ? left : right;
        }

        return s;
    }

    string longestNiceSubstring(string s) {
        return divide(s);
    }
};