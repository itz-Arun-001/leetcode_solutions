class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        int n = series1.size(), m = series2.size();
        vector<int> ts;
        int p = 0, q = 0;
        while (p < n || q < m) {
           int t;
            if (p < n && (q >= m || series1[p][0] <= series2[q][0])) {
                t = series1[p][0];
                if (q < m && series2[q][0] == t)
                    q++;
                p++;
            } else {
                t = series2[q][0];
                q++;
            }
            ts.push_back(t);
        }
        int i = n - 1, j = m - 1;
       int val1 = 0, val2 = 0;
        vector<vector<int>> ans;
        for (int k = (int)ts.size() - 1; k >= 0; k--) {
            int t = ts[k];
            while (i >= 0 && series1[i][0] >= t) {
                val1 = series1[i][1];
                i--;
            }
            while (j >= 0 && series2[j][0] >= t) {
                val2 = series2[j][1];
                j--;
            }
            ans.push_back({t, (int)(val1 + val2)});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};