/*class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        while(true)
        {   
            ans.push_back(nums);
            int i=n-2;
            while(i>=0&&nums[i]>=nums[i+1])
                i--;
            if(i<0)
                break;
            int j=n-1;
            while(nums[j]<=nums[i])
                j--;
            swap(nums[j],nums[i]);
            reverse(nums.begin()+i+1,nums.end());
            
        }
        return ans;

        
    }
};*/

class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>& nums,vector<int>&temp,unordered_map<int,int>&mp,int &n)
    {
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
           /* if(i>idx&&nums[i]>nums[i-1])
            {
                continue;
            }
            if(mp[nums[i]]!=0)
            {
            temp.push_back(nums[i]);
            mp[nums[i]]--;
            help(nums,temp,mp,n);
            temp.pop_back();
            mp[nums[i]]++;
            
            }
            */
            for(auto &p : mp) {
                if(p.second == 0)
                    continue;
                temp.push_back(p.first);
                p.second--;
                help(nums, temp, mp, n);
                p.second++;
                temp.pop_back();
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        vector<int>temp;
        unordered_map<int,int>mp;
        for(int n:nums) mp[n]++;
        int n=nums.size();
        help(nums,temp,mp,n);
        return ans;
    }
};
