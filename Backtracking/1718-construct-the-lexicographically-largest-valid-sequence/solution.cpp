class Solution {
public:
    bool help(vector<int>& ans, vector<bool>& used, int idx, int n) {
        if (idx==ans.size())
            return true;
        if (ans[idx]!=0)
            return help(ans,used,idx+1,n);
        for (int x=n;x>=1;x--) {
            if (used[x])
                continue;
            if (x==1) {
                ans[idx]=1;
                used[1]=true;
                if (help(ans,used,idx+1,n))
                    return true;
                ans[idx]=0;
                used[1]=false;
            }
            else {
                int second=idx+x;
                if (second>=ans.size()||ans[second]!=0)
                    continue;
                ans[idx]=x;
                ans[second]=x;
                used[x]=true;
                if (help(ans, used, idx + 1, n))
                    return true;
                ans[idx]=0;
                ans[second]=0;
                used[x]=false;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,0);
        vector<bool> used(n+1,false);
        help(ans,used,0,n);
        return ans;
    }
};
