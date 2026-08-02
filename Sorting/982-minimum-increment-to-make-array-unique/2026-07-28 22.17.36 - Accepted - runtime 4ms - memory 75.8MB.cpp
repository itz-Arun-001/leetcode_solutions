/*
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int next = prev + 1;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= prev) {
                ans += next - nums[i];
                nums[i] = next++;
                prev = nums[i];
            }
            if (nums[i] > prev) {
                prev = nums[i];
                next = prev + 1;
            }
        }
        return ans;
    }
};*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] > 1) {
                int extra = freq[i] - 1;
                freq[i + 1] += extra;
                ans += extra;
            }
        }
        return ans;
    }
};