class Solution {
public:
   static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[2]<b[2]) return true;
        return false;
    }
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int n=rows,m=cols;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans.push_back({i,j,abs(i-rCenter)+abs(j-cCenter)});
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        for(auto &v : ans)
          v.pop_back();
        return ans;
    }
};
