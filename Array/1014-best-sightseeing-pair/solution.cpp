class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=0;
        int mx=values[0]+0;
        int temp1,temp2;
        for(int i=1;i<n;i++)
        {
            temp1=values[i]+i;
            temp2=values[i]-i;
            ans=max(ans,mx+temp2);
             mx=max(mx,temp1);
        }
        return ans;
    }
};
