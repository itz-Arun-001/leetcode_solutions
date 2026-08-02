class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1=s.size();
        int n2=p.size();
        vector<int>ans;
        vector<int>a(26,0),b(26,0);
        for(int i=0;i<n2;i++)
        
        {
            a[p[i]-'a']++;
        }
      int l=0;
        for(int r=0;r<n1;r++)
        {
            b[s[r]-'a']++;
            if(r-l+1>n2)
            {
                b[s[l]-'a']--;
                l++;
            }
            if(a==b)    ans.push_back(l);

        }
        return ans;
    }
};