class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int temp=n;
        int ans=0;
        while(temp>0)
        {
            ans=(ans<<1)|1;
            temp>>=1;
        }
        return n^ans;

        
    }
};
