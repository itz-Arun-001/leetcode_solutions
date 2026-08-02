class Solution {
public:
    int maximumLengthSubstring(string s) {

        int l = 0;
        unordered_map<char, int> mp;
        int ans = 0, temp = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            string t;
            t += s[i];
            mp[s[i]]++;
            if (mp[s[i]] <= 2)
                ans = max(ans, i - l + 1);
            while (mp[s[i]] > 2) {
                mp[s[l]]--;
                
                l++;
            }
        }
        return ans;
    }
};