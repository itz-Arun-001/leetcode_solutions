class Solution {
public:
    vector<string>ans;
    void help(string temp,int &ocnt,int &ccnt,int &n)
    {
        if(ocnt==n&&ccnt==n)
        {
            ans.push_back(temp);
            return;
        }
        if(ocnt>n||ccnt>n) return;
        if(ocnt<n)
        {
            ocnt++;
            temp.push_back('(');
            help(temp,ocnt,ccnt,n);
            ocnt--;
            temp.pop_back();
        }
        if(ccnt<ocnt)
        {
            ccnt++;
            temp.push_back(')');
            help(temp,ocnt,ccnt,n);
            ccnt--;
            temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        int o=0,c=0;
        help(temp,o,c,n);
        return ans;
        
    }
};
