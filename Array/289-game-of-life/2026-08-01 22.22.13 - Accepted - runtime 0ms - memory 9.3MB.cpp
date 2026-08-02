class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr == 0 && dc == 0)
                            continue;
                        int nr = i + dr;
                        int nc = j + dc;
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                            if (board[nr][nc] == 1 || board[nr][nc] == -1)
                                live++;
                        }
                    }
                }
                if((board[i][j]==-1||board[i][j]==1)&&(live<2||live>3))
                    board[i][j]=-1;
                if((board[i][j]==0||board[i][j]==2)&&(live==3))
                {
                    board[i][j]=2;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==-1) board[i][j]=0;
               else  if(board[i][j]==2) board[i][j]=1;
            }
        }
      
    }
};