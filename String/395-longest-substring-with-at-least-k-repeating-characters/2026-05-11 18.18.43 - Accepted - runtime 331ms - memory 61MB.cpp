class Solution {
public:

    int solve(string s, int k) {

        int n = s.size();

        if(n < k)
            return 0;

        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        for(int i = 0; i < n; i++) {

            if(freq[s[i]] < k) {

                int l = solve(s.substr(0, i), k);

                int r = solve(s.substr(i + 1), k);

                return max(l, r);
            }
        }

        return n;
    }

    int longestSubstring(string s, int k) {
        return solve(s, k);
    }
};