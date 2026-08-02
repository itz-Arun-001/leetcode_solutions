class Solution {
public:
    long long k;
    string s;

    long long dp[20][11][2][2];

    long long dfs(int pos, int prev, int tight, int started) {
        if (pos == (int)s.size()) {
            return started;
        }

        long long &res = dp[pos][prev][tight][started];

        if (!tight && res != -1)
            return res;

        long long ans = 0;
        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);

            if (!started) {
                if (d == 0) {
                    ans += dfs(pos + 1, 10, ntight, 0);
                } else {
                    ans += dfs(pos + 1, d, ntight, 1);
                }
            } else {
                if (abs(d - prev) <= k) {
                    ans += dfs(pos + 1, d, ntight, 1);
                }
            }
        }

        if (!tight)
            res = ans;

        return ans;
    }

    long long solve(long long x) {
        if (x < 0)
            return 0;

        s = to_string(x);
        memset(dp, -1, sizeof(dp));

        return dfs(0, 10, 1, 0);
    }

    long long goodIntegers(long long l, long long r, int kk) {
        k = kk;

        auto denoluvira = make_tuple(l, r, kk);

        return solve(r) - solve(l - 1);
    }
};