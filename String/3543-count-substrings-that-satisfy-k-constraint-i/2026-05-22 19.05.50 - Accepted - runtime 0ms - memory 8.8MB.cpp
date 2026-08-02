class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int l=0;
        int zc=0;
        int oc=0;
        int n=s.size();
        int ans=0;

        for(int r=0;r<n;r++)
        {
            if(s[r]=='0')
                zc++;
            else    oc++;
            while(zc>k&&oc>k)
                {
                    if(s[l]=='0')   zc--;
                    else    oc--;
                    l++;
                }
            ans+=r-l+1;

        }
        return ans;

        
    }
};