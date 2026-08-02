class Solution {
public:
    int largestInteger(int n, int s) {
       
        long long du=0;
        long long ans=0;
         if(s==0) return 0;
        if(s>9*n) return -1;
        while(s>0)
            {
            int add=min(9,s);
            ans=ans*10+add;
            s-=add;
            du++;
            }
        for(int i=du;i<n;i++)
            {
                ans*=10;
            }
        return (int)ans;
    }
};