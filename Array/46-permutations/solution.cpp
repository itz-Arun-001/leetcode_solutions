/*class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;

        // IMPORTANT: sort first
        sort(nums.begin(), nums.end());

        while(true) {
            
            ans.push_back(nums);

            int n = nums.size();
            int i = n - 2;

            // Step 1: find breakpoint
            while(i >= 0 && nums[i] >= nums[i+1])
                i--;

            if(i < 0)
                 break;

            int j = n - 1;

            // Step 2: find just greater element
            while(nums[j] <= nums[i])
                j--;

            // Step 3: swap
            swap(nums[i], nums[j]);

            // Step 4: reverse suffix
            reverse(nums.begin() + i + 1, nums.end());
        }

        return ans;
    }
};

*/
class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>&nums,unordered_map<int,int>&mp,vector<int>& st)
    {
        int n=nums.size();
        if(st.size()==n)
        {
            ans.push_back(st);
            return ;
        }
        for(int i=0 ;i<n;i++)
        {
            if(mp[i]==0)
            {
               mp[i]=1;
               st.push_back(nums[i]); 
               help(nums,mp,st);
               st.pop_back();
                mp[i]=0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>st;
        unordered_map<int,int>mp;
        help(nums,mp,st);
        return ans;
    }
};
