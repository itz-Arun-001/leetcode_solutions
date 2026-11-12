class Solution {
public:
    int rotatedDigits(int n) {
        vector<int>dp={1,1,2,0,0,2,2,0,1,2};
        int cnt=0;
        bool valid,chan;
        for(int i=0;i<=n;i++)
        {
            valid=true;
            chan=false;
            int x=i;
            while(x>0)
            {
                int a=x%10;
                x/=10;
                if(dp[a]==0)
                {
                    valid=false;
                    break;
                }
                if(dp[a]==2) {
                    chan=true;
                }
            }
            if(chan&&valid) cnt++;
        }
        return cnt;
        

    }
};
