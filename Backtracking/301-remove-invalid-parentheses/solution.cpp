/*class Solution {
public:
    int isvalid(string s)
    {
        // ->int val=0;
        // for(char &c :s)
        // {
        //     if(c=='(') val++;
        //     else if(c==')') val--;
        // }
        // return abs(val);<-
        stack<char>st;
        for(char &c: s)
        {
            if(c=='(')
            {
                st.push(c);
            }
            if(c==')')
            {
                if(!st.empty()&&st.top()=='(')
                    st.pop();
                else st.push(c);
            }
        }
        return st.size();
    }
    vector<string >ans;
    unordered_set<string>st;
    void help(string s,int diff)
    {
        if(st.count(s)!=0) return;
        if(diff<0)
        {
            return;
        }
        if(diff==0)
        {
            if(!isvalid(s))
                st.insert(s);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != '(' && s[i] != ')')
                continue;
            if(i > 0 && s[i] == s[i-1])
                continue;
            string l=s.substr(0,i);
            string r=s.substr(i+1);
            help(l+r,diff-1);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        //int n=s.size();
        help(s,isvalid(s));
        for(auto& str : st)
        {
            ans.push_back(str);

        }
        return ans;
    }
};*/

class Solution {
public:

    vector<string> ans;
    unordered_set<string> st;

    void help(string s,int pos,int eo,int ec)
    {
        if(eo==0&&ec==0)
        {
            int bal=0;
            for(char c:s)
            {
                if(c=='(')
                    bal++;
                else if(c==')')
                    {
                        if(bal>0) bal--;
                        else return;
                    }
            }
            if(bal==0) st.insert(s);
            return;
        }
        for(int i=pos;i<s.size();i++)
        {
            if(i>pos&&s[i]==s[i-1]) continue;
            if(s[i]=='('&&eo>0)
            {
                string x=s.substr(0,i)+s.substr(i+1);
                help(x,i,eo-1,ec);
            }
            if(s[i]==')'&&ec>0)
            {
                string x=s.substr(0,i)+s.substr(i+1);
                help(x,i,eo,ec-1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {
        int eo=0,ec=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                eo++;
            else if(s[i]==')'){
                if(eo>0) eo--;
                else ec++;
            }
        }
        help(s,0,eo,ec);
        for(string x:st)
        {
            ans.push_back(x);
        }
        return ans;
    }
};
