/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        //sort(nums.begin(),nums.end());
        while(l<r)
        {
            if(nums[l]+nums[r]==target)   return {l,r};
            else if(nums[l]+nums[r]>target)  r--;
            else l++;
        }
        return {};
    }
};
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int rem=target-nums[i];
            if(mp.count(rem))
            {
                return {mp[rem],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};

