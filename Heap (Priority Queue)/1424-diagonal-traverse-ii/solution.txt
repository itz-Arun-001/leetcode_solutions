/*class Solution {
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
};*/


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        int mxd=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                int s=i+j;
                mp[s].push_back(nums[i][j]);
                mxd=max(s,mxd);

            }
        }
        int mnd=0;
        vector<int>ans;
        while(mnd<=mxd)
        {
            for(int x:mp[mnd])
            {
                ans.push_back(x);
            }
            mnd++;
        }
        return ans;
    }
};
