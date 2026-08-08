class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int maxend=0;
        for(auto &m:intervals)
        {
            maxend=max(maxend,m[1]);
        }
        maxend=maxend+1;
        vector<int>diff(maxend+1,0);
        for(auto &m:intervals)
        {
            diff[m[0]]+=1;
            diff[m[1]+1]-=1;
        }
        int ans=0;
        int sum=0;
        for(auto& i:diff)
        {
            sum+=i;
            ans=max(ans,sum);

        }
        return ans;        
        
    }
};
