class Solution {
public:
    int ans=INT_MAX;
    void help(vector<int>& cook,int&k,int& n,int idx,vector<int>& child)
    {
        if(idx==n)
        {
            int temp=0;
            for(int x: child)
            {
                temp=max(x,temp);
            }
            ans=min(ans,temp);
            return;
        }
        for(int i=0;i<k;i++)
        {
            child[i]+=cook[idx];
            help(cook,k,n,idx+1,child);
            child[i]-=cook[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        int n=cookies.size();
        help(cookies,k,n,0,child);
        return ans;
    }
};
