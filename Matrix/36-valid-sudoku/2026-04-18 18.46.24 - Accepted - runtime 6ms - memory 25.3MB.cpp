/*class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> r, c;
        unordered_map<char, pair<int, int>> b;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j]=='.')    continue;
                if (r.find(board[i][j]) != r.end() ||
                    c.find(board[i][j]) != c.end() ||
                    b.find(board[i][j]) != b.end())
                    return false;
                r[board[i][j]] = i;
                c[board[i][j]] = j;
                b[board[i][j]] = {i / 3, j / 3};
            }
        }
        return true;
    }
};*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<unordered_set<char>>r(9),c(9),b(9);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                char key=board[i][j];
                if(key == '.')  continue;
                int box=(i/3)*3+(j/3);
                if(r[i].count(key)||c[j].count(key)||b[box].count(key))    return false;
                r[i].insert(key);
                c[j].insert(key);
                b[box].insert(key);

             
            }
        }
        return true;
    }
};
