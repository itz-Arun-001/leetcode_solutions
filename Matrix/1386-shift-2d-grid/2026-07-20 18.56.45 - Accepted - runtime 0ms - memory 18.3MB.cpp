class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int totele = row * col;
        k %= totele;
        vector<vector<int>> ans(row, vector<int>(col));
        for (int i = 0; i < row; i++)

        {
            for (int j = 0; j < col; j++) {
                int oldIndex = i * col+ j;
                int newidx = (oldIndex + k) % totele;
                int nrow = newidx / col;
                int ncol = newidx % col;
                ans[nrow][ncol] = grid[i][j];
            }
        }
        return ans;
    }
};
