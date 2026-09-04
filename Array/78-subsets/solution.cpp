class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>& nums,int idx,vector<int>& temp)
    {
        ans.push_back(temp);
        for(int i=idx;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            help(nums,i+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        help(nums,0,temp);
        return ans;
        
    }
};
