class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string t="";
        for(char c:path){
            if(c=='/')
            {
                if(t==".."&&!st.empty())
                {
                    st.pop();
                }
                else{
                    if(t!=".."&&t!=""&&t!="."){  st.push(t);
                    }
                }
                t="";
            }
            else  t+=c;
        }
         if (t == ".." && !st.empty()) {
            st.pop();
        }
        else if(t!=""&&t!=".."&&t!=".")  st.push(t);
        t="";
        vector<string>v;
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        for(int i=0;i<v.size();i++)
        {
            t+="/";
            t+=v[v.size()-1-i];
        }
        return (t=="")?"/":t;
    }
};