class Solution {
public:
    int maxVowels(string s, int k) {
        int maxc=-1;
        int c=0;
        int l=0;
        for(int r=0;r<s.size(); r++)
            {
                if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u' )
                {
                    c++;
                }
                while((r-l+1)>k)
                {
                    if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u' ) c--;
                    l++;
                }
                maxc=max(maxc,c);
                
            }
        return maxc;
        
    }
};