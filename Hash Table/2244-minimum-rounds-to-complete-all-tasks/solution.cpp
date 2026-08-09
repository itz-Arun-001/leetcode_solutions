class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(auto x: tasks)
        {
            mp[x]++;
        }
        int ans=0;
        for(auto it:mp)
        {
           if(it.second==1) return -1;
           else ans+=ceil((double)it.second/3);
        }
        return ans; 
    }
};
