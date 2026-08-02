class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0)
            return {};
        vector<int> ans;
        unordered_map<int, int> freq;
        for (int x : changed)
            freq[x]++;
        sort(changed.begin(), changed.end());
        for (int i = 0; i < changed.size(); i++) {
            if (freq[changed[i]] == 0)
                continue;

            if (changed[i] == 0 && freq[0] < 2)
                return {};

            if (freq[2 * changed[i]] == 0)
                return {};

            ans.push_back(changed[i]);
            freq[changed[i]]--;
            freq[2 * changed[i]]--;

            if (freq[changed[i]] == 0)
                freq.erase(changed[i]);

            if (freq.count(2 * changed[i]) && freq[2 * changed[i]] == 0)
                freq.erase(2 * changed[i]);
        }
        return ans;
    }
};