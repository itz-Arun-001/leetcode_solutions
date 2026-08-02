class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int n = nums.size();
        int k = st.size();
        int ans = 0;
        int l = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == 1)
                count++;
            while (count == k) {
                ans += n - i;
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    count--;
                l++;
            }
        }
        return ans;
    }
};