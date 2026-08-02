class Solution {
public:
    int largestInteger(int n, int s) {
        if(s==0) return 0;
        if(s>9*n) return -1;
        long long du=0;
        long long ans=0;
        while(s>0)
            {
            int d=min(9,s);
            ans=ans*10+d;
            s-=d;
            du++;
            }
        for(int i=du;i<n;i++)
            {
                ans*=10;
            }
        return (int)ans;
    }
};