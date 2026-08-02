class Solution {
public:
  
    int maximumSum(vector<int>& nums) {
        int maxans =-1;
        unordered_map<int, int> mp;
        for (int i=0;i<nums.size();i++) {
            int sum = 0;
            int num=nums[i];
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            if (mp.count(sum) != 0) {
                maxans = max(maxans, mp[sum] + nums[i]);
                mp[sum]=max(mp[sum],nums[i]);
               

            } else
                mp[sum] = nums[i];
        }
        return maxans;
    }
};