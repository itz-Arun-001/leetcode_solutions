class Solution {
public:
    bool ispossible(vector<int>& nums,int t,int val){
        int ans=0;
        for( int i=0;i<nums.size();i++)
            {
                ans+= ceil((
                            double)nums[i]/val);
                
            }
        return ans<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
     //   int low=*min_element(nums.begin(),nums.end());
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(ispossible(nums,threshold,mid)){
                    ans=min(ans,mid);
                    high=mid-1;
                }
                else low=mid+1;
            }
        return ans;
    }
};