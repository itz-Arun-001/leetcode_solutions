class NumMatrix {
public:
    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix):prefix(matrix.size()+1,vector<int>(matrix[0].size()+1,0)){
         int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
             {
                prefix[i+1][j+1]=matrix[i][j]+prefix[i][j+1]+prefix[i+1][j]-prefix[i][j];
               // ans.push_back(prefix[i+1][j+1]);
             }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        return prefix[row2+1][col2+1]-prefix[row1][col2+1]-prefix[row2+1][col1]+prefix[row1][col1];
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
