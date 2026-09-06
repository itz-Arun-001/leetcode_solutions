class Solution {
public:
    string maximumXor(string s, string t) {
        int zcnt=0,ocnt=0,n=s.size();
        for(char & c:t)
        {
            if(c=='0') zcnt++;
            else ocnt++;
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1'&&zcnt>0)
            {
                ans+='1';
                zcnt--;
            }
            else if(s[i]=='0'&&ocnt>0)
            { 
                ans+='1';
                ocnt--;
            }
            else{
                 ans += '0';
                if(s[i] == '0')
                    zcnt--;
                else
                    ocnt--;
            }
        }
        //reverse(t.begin(),t.end());
        return ans;
        
    }
};
