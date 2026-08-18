class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int mtot=accumulate(rolls.begin(),rolls.end(),0);
        int req=(mean*(m+n))-mtot;
        if(req < n || req > 6*n)
             return {};
        vector<int>ans(n,1);
        if(req==n) return ans;
        req=req-n;
        int i=0;
        while(req>0&&i<n)
        {
            int temp=min(req,5);
            ans[i]+=temp;
            req-=temp;
            i++;
            

        }
        return ans;

        
    }
};
