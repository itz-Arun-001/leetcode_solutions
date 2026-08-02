class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int sum=0,temp=0;
        vector<int>fr(10001,0);
        for(int r=0;r<n;r++)
        {
            fr[nums[r]]++;
            temp+=nums[r];
            while(fr[nums[r]]>1)
            {
            fr[nums[l]]--;
                temp-=nums[l];
                //if(mp[nums[l]]==0)  mp.erase(nums[l]);
                l++;
            }
            sum=max(sum,temp);
        
        }
    return sum;    
    }
};