/*class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int dif = mx - mn;
        auto max_it = max_element(nums.begin(), nums.end());
        int maxidx = distance(nums.begin(), max_it);
        auto min_it = min_element(nums.begin(), nums.end());
        int minidx = distance(nums.begin(), min_it);
        nums[minidx] += k;
        nums[maxidx] -= k;
        mn = *min_element(nums.begin(), nums.end());
        mx = *max_element(nums.begin(), nums.end());
        dif = min(dif, mx - mn);
        return dif;
    }
};
*/
/*
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int dif = mx - mn;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            nums[l++]+=k;
            nums[r--]-=k;
        }
         mn = *min_element(nums.begin(), nums.end());
        mx = *max_element(nums.begin(), nums.end());
        dif=min(dif,mx-mn);
        return dif;
    }
};*/
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        for (int i = 0; i < n - 1; i++) {
            int mx = max(nums[n - 1] - k, nums[i] + k);
            int mn = min(nums[0] + k, nums[i + 1] - k);
            ans = min(ans, mx - mn);
        }
        return ans;
    }
};