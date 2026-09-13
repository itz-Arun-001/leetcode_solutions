class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(search(board,word,i,j,0,n,m))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool search(vector<vector<char>>& board,string &word,int row,int col,int pos,int &n,int &m)
    {
        if(pos==word.size()) return true;
        if(row<0||col<0||row>=n||col>=m||board[row][col]!=word[pos]||board[row][col]=='@'){
             return false;
        }
        char temp=board[row][col];
        board[row][col]='@';
        bool left=search(board,word,row,col-1,pos+1,n,m);
        bool right=search(board,word,row,col+1,pos+1,n,m);
        bool up=search(board,word,row-1,col,pos+1,n,m);
        bool down=search(board,word,row+1,col,pos+1,n,m);
         board[row][col]=temp;
        if(left||right||up||down)
            return true;
        return false;
    }
};
