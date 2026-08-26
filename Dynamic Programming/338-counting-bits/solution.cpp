class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
       /* for(int i=0;i<=n;i++)
        {
            int cnt=0;
            int x=i;
            while(x!=0)
            {
                cnt+=x&1;
                x>>=1;
            }
            ans[i]=cnt;
        }*/
        for(int i=1;i<=n;i++) {
            ans[i]=ans[i>>1]+(i&1);
        }

        return ans;
        
    }
};
