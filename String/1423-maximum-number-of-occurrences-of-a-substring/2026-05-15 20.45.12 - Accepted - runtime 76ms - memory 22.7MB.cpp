class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans=0;
        int l=0;
        int r=0,n=s.size();
        unordered_map<char,int>mp;
        unordered_map<string,int>freq;
     


        while(r!=n)
        {
            mp[s[r]]++;
           
            if(r-l+1>minSize)
            {
                mp[s[l]]--;
                
                 if(mp[s[l]]==0)     mp.erase(s[l]);
                 l++;
            }
            if(r-l+1==minSize&&mp.size()<=maxLetters)

            { string sub = s.substr(l, minSize);

                freq[sub]++;

                ans = max(ans, freq[sub]);
                
            }
            r++;

        }
        return ans;
        
    }
};