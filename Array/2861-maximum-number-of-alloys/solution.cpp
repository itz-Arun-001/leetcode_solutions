class Solution {
public:
    bool check(int &n,int &k,int &budget,vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost,long long &m)
    {
        
        for(int i=0;i<k;i++)
        {
            long long  buy=0;
            long long s=stock.size();
            //vector<long long> req(s,0LL);
            long long req=0LL;
            for(int j=0;j<s;j++)
            {
                req=composition[i][j]*m;
                if(req>stock[j])
                {
                    buy+=(req-stock[j])*cost[j];
                    if(buy > budget)
                         break;
                }
            }
            
            if(buy<=budget) return true;
           
        }
        return false;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
       long long l=1;
       long long h = 10e9;
        long long ans=0;
        while(l<=h)
        {
            long long m=l+(h-l)/2;
            if(check(n,k,budget,composition,stock,cost,m))
            {
                ans=max(ans,m);
                l=m+1;
            }

            else h=m-1;
        }
        return ans;
    }
};
