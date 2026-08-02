class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        
        auto torqavemi = make_pair(edges, baseTime);

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<long long> finish(n);

        function<long long(int)> dfs = [&](int u) -> long long {

            if (adj[u].empty()) {
                return finish[u] = baseTime[u];
            }

            long long mn = LLONG_MAX;
            long long mx = LLONG_MIN;

            for (int v : adj[u]) {
                long long child = dfs(v);
                mn = min(mn, child);
                mx = max(mx, child);
            }

            return finish[u] = 2 * mx - mn + baseTime[u];
        };

        return dfs(0);
    }
};