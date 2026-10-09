class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        stack<int>st;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
           if(s[i]=='(') 
           {
               st.push(s[i]);
           }else
           {
               if(i+1<n&&s[i+1]==s[i])
                   i++;
               else cnt++;
               if(!st.empty()){
                   st.pop();
               }
               else cnt++;
           }
            
        }
        cnt+=2*st.size();
        return cnt;
    }
};
