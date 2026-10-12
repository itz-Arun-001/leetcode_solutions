class Solution {
public:
    void help(string& s,int &n)
    {
        if(n==1) s+='1';
        else{
            int x=s.size();
            string temp="";
            int cnt=0;
            int i;
            for( i=0;i<x;i++)
            {
                if(i>0&&s[i]!=s[i-1])
                {
                    temp+=to_string(cnt)+s[i-1];
                    cnt=0;
                }
                cnt++;
            }
            temp+=to_string(cnt)+s[i-1];
            s=temp;
        }
    }
    string countAndSay(int n) {
        string ans="";
        for(int i=1;i<=n;i++)
        {
            help(ans,i);
        }
        return ans;
    }
};
