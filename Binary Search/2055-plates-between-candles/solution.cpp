class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefix(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> ans;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (i == 0)
                    prefix[i] = 1;
                else
                    prefix[i] = prefix[i - 1] + 1;
            } else {
                if (i > 0)
                    prefix[i] = prefix[i - 1];
            }
            if (s[i] == '|')
                idx = i;
            left[i] = idx;
        }
        idx = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|')
                idx = i;
            right[i] = idx;
        }
        for (auto& v : queries) {
            int l = v[0];
            int r = v[1];
            int start = right[l];
            int end = left[r];
            if (start == -1 || end == -1 || start >= end)
                ans.push_back(0);
            else
                ans.push_back(prefix[end] - prefix[start]);
        }
        return ans;
    }
};
