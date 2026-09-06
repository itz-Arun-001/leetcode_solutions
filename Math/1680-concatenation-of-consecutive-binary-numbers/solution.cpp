class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=0;
        const int MOD=1e9+7;
        int dig=1;
        for(int i=1;i<=n;i++)
        {
            if(i==(1<<dig)) dig++;
            ans=((ans<<dig)+i)%MOD;
        }
        return ans;
        
    }
};
