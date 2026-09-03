class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>prefixxr(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefixxr[i+1]=prefixxr[i]^arr[i];
        }
        vector<int>ans;
        for(auto &it: queries)
        {
            int a=it[0];
            int b=it[1];
            ans.push_back(prefixxr[a]^prefixxr[b+1]);
        }
        return ans;

        
    }
};
