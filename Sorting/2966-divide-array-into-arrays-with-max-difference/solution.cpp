class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),cnt=n/3;
        vector<vector<int>>ans;
        int a=0,b=a+1,c=b+1;
        while(c<n)
        {
            if(abs(nums[a]-nums[b])<=k&& abs(nums[a]-nums[c])<=k&&abs(nums[b]-nums[c])<=k) {
                ans.push_back({nums[a],nums[b],nums[c]});
               a+=3;
                b+=3;c+=3;
            }
            else {
              return {};
            }
        }
        return ans;

        
    }
};
