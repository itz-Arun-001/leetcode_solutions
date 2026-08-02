class Solution {
public:
    bool ispossible(vector<int>& nums,int day,int val){
        int load=0;
        int days=1;
        for(int num:nums)
            {
                if(load+num>val)
                {
                    days++;
                    load=num;
                }
                else load+=num;
            }
        return days<=day;
    }
    int shipWithinDays(vector<int>& weight, int days) {
        int low=*max_element(weight.begin(),weight.end());
        int high=accumulate(weight.begin(),weight.end(),0);
        int ans=INT_MAX;
        while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(ispossible(weight,days,mid))
                {
                    ans=min(ans,mid);
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        return ans;
        
    }
};