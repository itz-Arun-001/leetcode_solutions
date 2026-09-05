class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>& nums,int idx,vector<int>& temp,int& n)
    {
        ans.push_back(temp);
        for(int i=idx;i<n;i++)
        {
            if(i>idx&&nums[i]==nums[i-1])
             continue;
            temp.push_back(nums[i]);
            help(nums,i+1,temp,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        if(n==0)return{};
        sort(nums.begin(),nums.end());
        help(nums,0,temp,n);
        return ans;
    }
};
