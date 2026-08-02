class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int sum=0,temp=0;
        unordered_map<int,int>mp;
        for(int r=0;r<n;r++)
        {
            mp[nums[r]]++;
            temp+=nums[r];
            while(mp[nums[r]]>1)
            {
                mp[nums[l]]--;
                temp-=nums[l];
                if(mp[nums[l]]==0)  mp.erase(nums[l]);
                l++;
            }
            sum=max(sum,temp);
        
        }
    return sum;    
    }
};