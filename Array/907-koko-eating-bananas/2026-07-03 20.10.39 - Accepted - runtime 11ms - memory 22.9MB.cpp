class Solution {
public:
    long long tr(const vector<int>& nums, int t) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += ceil((double)nums[i] / t); // integer ceiling
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hr = tr(piles, mid);
            if (hr <= h) {
                ans = min(ans, mid);
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};