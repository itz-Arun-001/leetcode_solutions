class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int a=queries.size();
        int b=logs.size();
        vector<pair<int,int>>p;
        for(int i=0;i<a;i++)
        {
            p.push_back({queries[i],i});
        }
        sort(p.begin(),p.end());
        sort(logs.begin(),logs.end(),cmp);
        unordered_map<int,int>mp;
        vector<int>ans(a);
        int left=0,right=0;
        for(auto & it: p)
        {
           
            int idx=it.second;
            int q=it.first;
             int low=q-x;
            while(right<b&&logs[right][1]<=q)
            {
                mp[logs[right][0]]++;
                right++;

            }
            while(left<right&&logs[left][1]<low)
            {
                mp[logs[left][0]]--;
                if(mp[logs[left][0]]==0)
                    mp.erase(logs[left][0]);
                left++;
            }
            ans[idx]=n-mp.size();

        }
        return ans;
    }
};
