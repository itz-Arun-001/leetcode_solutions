class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>>arr;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                arr.push_back({i+j,j,nums[i][j]});
            }
        }
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            ans.push_back(arr[i][2]);
        }
        return ans;
        
    }
};