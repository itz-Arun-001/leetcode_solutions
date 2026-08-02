class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(char a: s)
        {
            if(!st.empty())
            {
                if(st.top()==a)
                {
                    st.pop();

                }
                else{
                    st.push(a);
                }
            }
            else{
                st.push(a);
            }
        }
        string res="";
       
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};