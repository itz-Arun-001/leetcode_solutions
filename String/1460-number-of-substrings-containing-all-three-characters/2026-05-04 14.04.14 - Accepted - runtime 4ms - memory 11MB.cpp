class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0, ans = 0;
        vector<int> cnt(3, 0);

        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                cnt[s[l] - 'a']--;
                l++;
            }

            ans += l;
        }

        return ans;
    }
};