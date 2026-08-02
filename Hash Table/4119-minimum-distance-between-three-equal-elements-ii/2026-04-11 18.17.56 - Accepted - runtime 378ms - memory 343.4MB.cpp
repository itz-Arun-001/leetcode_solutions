class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
       int n= nums.size();
        // Store indices
        for(int i = 0; i <n; i++) {
            mp[nums[i]].push_back(i);
        }

        int mini = INT_MAX;

        // Check each value
        for(auto &it : mp) {
            vector<int>& v = it.second;
            
            if(v.size() < 3) continue;

            // Try all consecutive triplets
            for(int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i+2] - v[i]);//|(i-j)|+|(j-k)|+|(k-i)|=|i-j+j-k|+|(k-1)|=|i-k|+|k-i|=2*|k-i|
                mini = min(mini, dist);
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};