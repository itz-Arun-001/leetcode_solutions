/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int l = 0, r = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (mp.find(s[r])!=mp.end()&&mp[s[r]]>=l)
            {
                l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for(int i=0;i<256;i++)
        {
            hash[i]=-1;
        }
        int maxans=0;
        int ans=0,l=0,r=0,n=s.size();
        /*for(int i=0;i<n;i++)
        {
            if(hash[s[i]]!=-1&&hash[s[i]]>=l)
            {
                l=hash[s[i]]+1;
            }
            hash[s[i]]=r;
            ans=max(ans,r-l+1);
            r++;
        }*/
        while(r<n)
        {
            if(hash[s[r]]!=-1)
            {
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            hash[s[r]]=r;
            maxans=max(maxans,r-l+1);
            r++;

        }
        return maxans;
    }
};
