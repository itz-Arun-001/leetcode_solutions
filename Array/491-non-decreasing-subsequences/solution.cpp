/*class Solution {
public:
    set<vector<int>>st;
    vector<vector<int>>ans;
    void help(vector<int>& nums,int idx,vector<int>& temp,int &n)
    {
        if(temp.size()>1)
        {
            st.insert(temp);
        }
        if(temp.size()>=n) return;
        for(int i=idx;i<n;i++)
        {
            if(temp.empty()||nums[i]>=temp.back())
            {
            temp.push_back(nums[i]);
            help(nums,i+1,temp,n);
            temp.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
       // sort(nums.begin(),nums.end());
        int n=nums.size();
        help(nums,0,temp,n);
        for(auto s :st)
        {
            ans.push_back(s);
        }
        return ans;
    }
};*/
class Solution {
public:
    vector<vector<int>> ans;

    void help(vector<int>& nums, int idx, vector<int>& temp) {
        if(temp.size() >= 2)
            ans.push_back(temp);
        unordered_set<int> used;
        for(int i = idx; i < nums.size(); i++) {
            if(used.count(nums[i]))
                continue;
            if(!temp.empty() && nums[i] < temp.back())
                continue;
            used.insert(nums[i]);
            temp.push_back(nums[i]);
            help(nums, i + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        help(nums, 0, temp);
        return ans;
    }
};
