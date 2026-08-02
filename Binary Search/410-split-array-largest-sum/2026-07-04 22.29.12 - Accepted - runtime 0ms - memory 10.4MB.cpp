class Solution {
public:
    bool ispossible(vector<int>& nums,int limit,int val){
        int cnt=1;
        int last=0;
        for(int i=0;i<nums.size();i++){
            if(last+ nums[i]>val){
                cnt++;
                last=nums[i];
            }
            else last+=nums[i];
        }
        return cnt<=limit;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high= accumulate ( nums.begin(),nums.end(),0);
        int ans=INT_MAX;
        while (low<=high)
            {
                int mid=low+(high-low)/2;
                if(ispossible(nums,k,mid)){
                   ans =min(ans,mid);
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        return ans;
    }
};