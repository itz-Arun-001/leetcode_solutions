class Solution {
public:
    bool check(int m,vector<int>& q,int n)
    {
        int cnt=0;
        for(int i=0;i<q.size();i++)
        {
            cnt+=ceil((double)q[i]/m);
        }
        return cnt<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int ans=INT_MAX;
        int h=*max_element(quantities.begin(),quantities.end());
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(check(m,quantities,n))
            {
                ans=min(ans,m);
                h=m-1;
            }
            else{
                l=m+1;
            }

        }
        return ans;

        
    }
};
