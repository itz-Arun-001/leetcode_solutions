class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int l=0,ans=0;
        int tc=0,fc=0;

       /* for(int r=0;r<n;r++)
        {
            if(s[i]=="T")       tc++;
            else fc++;
        }*/
        int n=s.size();
        for(int r=0;r<n;r++)
        {
            if(s[r]=='T')   tc++;
            else    fc++;

            while(min(tc,fc)>k)
            {
                if(s[l]=='T')   tc--;
                else    fc--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};