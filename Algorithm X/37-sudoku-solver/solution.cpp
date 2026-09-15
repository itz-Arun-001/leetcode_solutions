class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        solve(board,m,n);
    }
    bool solve(vector<vector<char>>&board,int& m,int& n)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isvalid(board,i,j,c))
                        {
                            board[i][j]=c;
                            if(solve(board,m,n))
                            {
                                return true;
                            }
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;

    }
    bool isvalid(vector<vector<char>>&board,int& row,int& col,char& c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c) return false;
            if(board[i][col]==c) return false;
            if(board[3* (row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;

    }
};
