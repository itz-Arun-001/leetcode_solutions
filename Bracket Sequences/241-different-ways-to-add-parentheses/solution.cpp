class Solution {
public:
    unordered_map<string,vector<int>>dp;
    vector<int> help(string exp)
    {
        if(dp.find(exp)!=dp.end()) return dp[exp];
         int n=exp.size();
        char ch;
        vector<int> l,r;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*')
            {
                l.clear();
                r.clear();
                ch=exp[i];
                l=help(exp.substr(0,i));
                r=help(exp.substr(i+1,n));
                for(int x:l)
                {
                    for(int y:r)
                    {
                        if(ch=='+')
                            ans.push_back(x+y);
                        else if(ch=='-')
                            ans.push_back(x-y);
                        else ans.push_back(x*y);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(exp));
        dp[exp]=ans;
        return ans;
    }
    vector<int> diffWaysToCompute(string exp) {
        dp.clear();
        return help(exp);
    }
};

/*class Solution {
public:
    void help(string exp,vector<int>& ans)
    {
        bool f=false;
        for(int i =0;i<exp.size();i++)
        {   
            if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*')
            {
                f=true;
                break;
            }       
        }
        if(!f){
            int x=stoi(exp);
            ans.push_back(x);
            return;
        }
        int n=exp.size();
        char ch;
        vector<int> l,r;
        for(int i=0;i<n;i++)
        {
            if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*')
            {
                l.clear();
                r.clear();
                ch=exp[i];
                help(exp.substr(0,i),l);
                help(exp.substr(i+1,n),r);
                for(int x:l)
                {
                    for(int y:r)
                    {
                        if(ch=='+')
                            ans.push_back(x+y);
                        else if(ch=='-')
                            ans.push_back(x-y);
                        else ans.push_back(x*y);
                    }
                }
            }

        }
    }
    vector<int> diffWaysToCompute(string exp) {
        int n=exp.size();
        vector<int>ans;
        help(exp,ans);
        return ans;
    }
};*/
