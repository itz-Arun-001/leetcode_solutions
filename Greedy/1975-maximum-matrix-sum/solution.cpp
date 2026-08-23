class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int nc=0,zc=0;
        long long tot=0;
        int n=matrix.size();
        int m=matrix[0].size();
        int low=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]<0){
                     nc++;
                    
                }
                else if(matrix[i][j]==0) zc++;
                tot+=abs(matrix[i][j]);
                 low=min(low,abs(matrix[i][j]));
            }
        }
        return nc%2==0||zc>0?tot:tot-2*low;

        
    }
};
