class Solution {
public:
    long long reverse(int num) {
        long long reversed = 0;
        while (num != 0) {
            int digit = num % 10;
            reversed = reversed * 10 + digit;
            num /= 10;
        }
        return reversed;
    }
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> mp;
        long long cnt = 0;

        for (int x : nums) {
            int val = x - reverse(x);
            cnt = (cnt + mp[val]) % MOD;
            mp[val]++;
        }

        return cnt;
    }
};

   /* int countNicePairs(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] - reverse(nums[i]);
        }
        unordered_map<int, long long>mp;
        long long cnt = 0;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]) != 0) {
               cnt = (cnt + mp[nums[i]]) % MOD;
            }
            mp[nums[i]]++;
        }

        return cnt;
    }
};*/