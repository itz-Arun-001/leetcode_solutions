class Solution {
public:
    vector<vector<string>>ans;
    void help(  vector<string>& board,int col,vector<int>& left,vector<int>& updiag,vector<int>& lwdiag,int& n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(left[row]==0&&updiag[row+col]==0&&lwdiag[n-1+col-row]==0)
            {
                board[row][col]='Q';
                left[row]=1;
                updiag[row+col]=1;
                lwdiag[n-1+col-row]=1;
                help(board,col+1,left,updiag,lwdiag,n);
                board[row][col]='.';
                left[row]=0;
                updiag[row+col]=0;
                lwdiag[n-1+col-row]=0;

            }

        }   
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>left(n,0),updiag(2*n-1,0),lwdiag(2*n-1,0);
        help(board,0,left,updiag,lwdiag,n);
        return ans;

    }
};
