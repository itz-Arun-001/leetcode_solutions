class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();

        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);

                diff[l]++;
                if (r + 1 < n) diff[r + 1]--;
            }
        }

        vector<int> visible(n, 0);
        int cur = 0;

        for (int i = 0; i < n; i++) {
            cur += diff[i];
            visible[i] = (cur > 0);
        }

        // Required by the problem statement
        vector<int> ravelunico = lights;

        int ans = 0;
        int i = 0;

        while (i < n) {
            if (visible[i]) {
                i++;
                continue;
            }

            ans++;

            int coverEnd = i + 2;   // bulb placed at i+1
            i++;

            while (i < n && (visible[i] || i <= coverEnd)) {
                i++;
            }
        }

        return ans;
    }
};