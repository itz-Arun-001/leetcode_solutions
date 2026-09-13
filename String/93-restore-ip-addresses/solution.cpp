class Solution {
public:
    vector<string>ans;
    void help(string s,string temp,int idx,int dots)
    {
        if(dots>4) return;
        if(dots==4&&idx==s.size())
        {
            ans.push_back(temp.substr(0,temp.size()-1));
            return;
        }
        for(int i=1;i<=3&&i+idx<=s.size();i++)
        {
            string a=s.substr(idx,i);
            if(a[0]=='0'&&a.size()>1)
            {
                break;
            }

            else if(stoi(a)<=255)
            {
                 help(s,temp+a+".",idx+i,dots+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        help(s,"",0,0);
        return ans;   
    }
};
