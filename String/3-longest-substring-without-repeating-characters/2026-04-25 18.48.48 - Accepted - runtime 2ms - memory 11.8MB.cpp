class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int l = 0, r = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (mp.find(s[r])!=mp.end()&&mp[s[r]]>=l)
            {
                l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};