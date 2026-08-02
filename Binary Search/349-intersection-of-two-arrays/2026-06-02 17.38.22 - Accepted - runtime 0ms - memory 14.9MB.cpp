class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        vector<int>ans;
        set<int >s;
        for(int i=0;i<m;i++)
            {
               mp1[nums1[i]]=1;
            }
        for(int i=0;i<n;i++)
            {
               mp2[nums2[i]]=1;
            }
        for(auto it : mp1)
            {
                if(mp2.count(it.first))                         s.insert(it.first);
            }
        for (auto n:s)
            {
                ans.push_back(n);
            }
        return ans;
    }
};