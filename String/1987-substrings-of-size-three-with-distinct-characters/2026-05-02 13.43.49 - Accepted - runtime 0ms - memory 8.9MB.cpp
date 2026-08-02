class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<3;i++)
        {
            mp[s[i]-'a']++;
            

        }
        if(mp.size()==3)  ans++;
        for(int i=3;i<n;i++)
        {
            //if(mp.count(s[i]-'a'))
            mp[s[i-3]-'a']--;
            if(mp[s[i-3]-'a']==0) mp.erase(s[i-3]-'a');
            mp[s[i]-'a']++;
            if(mp.size()==3)    ans++;


        }
        return ans;
        
    }
};