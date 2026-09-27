class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int i=0;
        string ans="";
        int n=s.size();
        unordered_map<string,string>mp;
        for(auto x :knowledge)
        {
            mp[x[0]]=x[1];
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]!='(')
            {
                ans+=s[i];
            }
           
            else if(s[i]=='(')
            {
                 string temp="";
                i++;
                while(s[i]!=')')
                {
                    temp+=s[i];
                    i++;
                }
                //i++;
                if(mp.find(temp)!=mp.end())
                    ans+=mp[temp];
                else ans+='?';

            }

        }
        return ans;
    }
};
