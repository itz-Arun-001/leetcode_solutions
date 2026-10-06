class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int n=s.size();
        //stack<char>st;
        int o=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') 
            {
                //st.push(s[i]);
                o++;
            }
            else{
                // if(st.empty()) cnt++;
                // else st.pop();
                if(o==0) cnt++;
                else o--;
            }
        }
        cnt+=o;
        return abs(cnt);
    }
};
