class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;int h=n-1;
        int a=0,b=0;
        while(l<h)
        {
            int ans=nums[l]+nums[h];
            if(ans==target){a=l;b=h;break;}
            else if(ans>target) h--;
            else    l++;
        }

    return {a+1,b+1};
    }
};