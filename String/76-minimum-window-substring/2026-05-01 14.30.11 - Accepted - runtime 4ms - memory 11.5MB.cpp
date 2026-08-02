class Solution {
public:
    string minWindow(string s, string t) {
        vector<char>ans;
        int m=s.size();
        int n=t.size();
        if(m<n) return "";
        unordered_map<char,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[t[i]]++;
        }
        int mini=INT_MAX;
        int si=-1;
        int l=0,count=0;
        for(int r=0;r<m;r++)
        {
            if(mp[s[r]]>0)  count++;
            mp[s[r]]--;
            while(count==n)
            {
                if(r-l+1<mini)
                {
                    mini=r-l+1;
                    si=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
  
        }
                  return si==-1?"":s.substr(si,mini);
    }
};