class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int m=n-k;
        int ans=INT_MIN;
        int lsum=0,rsum=0,r=n-1;
        for(int i=0;i<k;i++)
        {

            lsum+=card[i];
        }
        ans=max(ans,lsum+rsum);
        for(int i=k-1;i>=0;i--)
        {
            lsum-=card[i];
            rsum+=card[r--];
            ans=max(ans,lsum+rsum);
        }
        return ans;

    }
};