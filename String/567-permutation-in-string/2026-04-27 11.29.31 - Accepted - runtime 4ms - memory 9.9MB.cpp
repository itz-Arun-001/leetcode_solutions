class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        if(n<m) return false;
        vector<int>a(26,0),b(26,0);
        for(int i=0;i<m;i++)
        {
            a[s1[i]-'a']++;


        }
        int l=0;
        for(int r=0;r<n;r++)
        {
            b[s2[r]-'a']++;
            if(r-l+1>m)
            {
                b[s2[l]-'a']--;
                l++;
            }
            if(a==b)    return true;
        }
        return false;

        
    }
};