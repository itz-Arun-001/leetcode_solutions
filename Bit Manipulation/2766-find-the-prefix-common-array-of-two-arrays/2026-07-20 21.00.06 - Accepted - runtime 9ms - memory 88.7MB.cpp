class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<A.size();i++)
            {
                mp[A[i]].first=i;
                mp[B[i]].second=i;
            }
        vector<int>ans(A.size(),0);
       int cnt=0;
       for(int i=0;i<A.size();i++)
       {
        if(mp[A[i]].first<=i&&mp[A[i]].second<=i)
        {
            
            cnt++;
        }
        if(mp[B[i]].first<=i&&mp[B[i]].second<=i){
             if(A[i]!=B[i])
             cnt++;
        }

        ans[i]=cnt;
       }
       return ans;
        
    }
};