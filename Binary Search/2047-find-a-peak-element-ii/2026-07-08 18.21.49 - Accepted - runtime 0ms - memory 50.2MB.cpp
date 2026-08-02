class Solution {
public:
    int findmaxindex(vector<vector<int>>& mat,int col,int m,int n)
    {
        int maxval=-1;
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(mat[i][col]>maxval)
            {
                maxval=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0;
        int m=mat[0].size();
        int n=mat.size();
        int high=mat[0].size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int maxrowidx=findmaxindex(mat,mid,m,n);
            int left=mid-1>=0?mat[maxrowidx][mid-1]:-1;
            int right=mid+1<m?mat[maxrowidx][mid+1]:-1;
            if(mat[maxrowidx][mid]>left&&mat[maxrowidx][mid]>right)
            {
                return {maxrowidx,mid};
            }
            else if(mat[maxrowidx][mid]<left) high=mid-1;
            else low=mid+1;
            }
            return{-1,-1};
        
    }
};