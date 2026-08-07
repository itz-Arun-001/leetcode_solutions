class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long >>ans;
        map<long long,long long>mp;
        for(auto vec:segments)
        {
            int a=vec[0];
            int b=vec[1];
            mp[a]+=vec[2];
            mp[b]-=vec[2];
        }
        long long prev = -1;
        long long sum = 0;

    for (auto &[pos, change] : mp) {
        if (prev != -1 && sum > 0) {
          ans.push_back({prev,pos,sum});
        }

        sum += change;
        prev = pos;
    }
    return ans;       
    }
};
