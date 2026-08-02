class Solution {
public:
    bool ispossible(vector<int>& nums, int days, int m, int k) {
        int cnt = 0, tot = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > days) {
                tot += cnt / k;
                cnt = 0;
            } else
                cnt++;
        }
        tot += cnt / k;
        return tot >= m ? true : false;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int low = *min_element(bloom.begin(), bloom.end());
        int high = *max_element(bloom.begin(), bloom.end());
        int ans = INT_MAX;
        if ((long long)bloom.size() < (long long)m * k)
            return -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ispossible(bloom, mid, m, k)) {
                ans = min(ans, mid);
                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};