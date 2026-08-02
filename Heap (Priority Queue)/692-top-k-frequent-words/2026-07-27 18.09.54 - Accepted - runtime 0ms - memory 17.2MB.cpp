class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string s : words)
            freq[s]++;
        vector<pair<string, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            if(a.second==b.second) return a.first<b.first;
            return a.second > b.second; 
        });
        vector<string> ans(k);
        for(int i=0;i<k;i++)
        {
            ans[i]=vec[i].first;
        }
        return ans;
    }
};