class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n * n +1, 0);
        vector<bool> visit(n * n + 1, false);
        int a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[grid[i][j]] == false) {
                    visit[grid[i][j]] = true;
                    freq[grid[i][j]]++;
                } else
                    a = grid[i][j];
            }
        }
        int b;
        for(int i=1;i<n*n;i++)
        {
            if(freq[i]==0) {
                b=i;
                break;
            }
        }
        return{a,b};
    }
};