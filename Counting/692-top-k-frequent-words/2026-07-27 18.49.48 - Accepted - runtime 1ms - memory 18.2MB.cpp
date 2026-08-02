/* my solution
class Solution {
public:
    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string s : words)
            freq[s]++;
        vector<pair<string, int>> arr(freq.begin(), freq.end());
        /* sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
             if(a.second==b.second) return a.first<b.first;
             return a.second > b.second;
         });*/
/*  sort(arr.begin(), arr.end(), cmp);

  vector<string> ans(k);
  for (int i = 0; i < k; i++) {
      ans[i] = arr[i].first;
  }
  return ans;
}
};

*/
// optimal code using priority code : idea by chat gpt
class Solution {
public:
    class cmp {
    public:
        bool operator()(const pair<string, int>& a,
                        const pair<string, int>& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string s : words)
            freq[s]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        for (auto& it : freq) {
            pq.push(it);
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
