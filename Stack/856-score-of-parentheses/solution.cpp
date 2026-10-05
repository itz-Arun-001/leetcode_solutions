class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(0);
            }
            else{
                int top=st.top();
                st.pop();
                int s=(top==0)?1:2*top;
                // top=st.top();
                // st.pop();
                // st.push(s+top);
                if(st.empty()) st.push(s);
                else
                    st.top()+=s;
            }
        }
        return st.top();
    }
};
