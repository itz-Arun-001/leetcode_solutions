class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        if((m*n)!=(r*c)) return mat;
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0;i<m*n;i++)
        {
            int orr=i/n;
            int oc=i%n;
            int nr=i/c;
            int nc=i%c;
            ans[nr][nc]=mat[orr][oc];
        }
        return ans;
        
    }
};