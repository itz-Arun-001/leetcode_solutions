class Solution {
public:
    int check(int n)
    {
        int cnt=0;
        while(n>0)
        {
            if((n&1)==1) cnt++;
            n>>=1;
        }
    if(cnt==2||cnt==3||cnt==5||cnt==7||cnt==11||cnt==13||cnt==17||cnt==19)
        return 1;
    return 0;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            ans+=check(i);
        }
        return ans;
        
    }
};
