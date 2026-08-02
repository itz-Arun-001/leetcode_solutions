class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>mp(k);
        for (int x : arr) {
            mp[((x % k) + k) % k]++;
        }
        if (mp[0] % 2 != 0)
            return false;
        if (k % 2 == 0 && mp[k / 2] % 2 != 0)
            return false;
        for (int i = 1; i <= k / 2; i++) {
            if (i == k - i)
                continue;
            if (mp[i] != mp[k - i])
                return false;
        }
        return true;
    }
};