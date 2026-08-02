/*class Solution {
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
};*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = 1LL * n * n;

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSqSum = N * (N + 1) * (2 * N + 1) / 6;

        long long actualSum = 0;
        long long actualSqSum = 0;

        for (auto &row : grid) {
            for (int x : row) {
                actualSum += x;
                actualSqSum += 1LL * x * x;
            }
        }

        long long diff = actualSum - expectedSum;                 // repeated - missing
        long long sqDiff = actualSqSum - expectedSqSum;           // repeated² - missing²

        long long sum = sqDiff / diff;                            // repeated + missing

        int repeated = (diff + sum) / 2;
        int missing = sum - repeated;

        return {repeated, missing};
    }
};