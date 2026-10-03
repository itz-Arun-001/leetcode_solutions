 class Solution {
 public:
     int longestValidParentheses(string s) {
        int ans=0;
        stack<int>st;
         st.push(-1);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c=='(') st.push(i);
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                else ans=max(ans,i-st.top());
            }
        }
        return ans;
     }
 };

// class Solution {
// public:
//     int longestValidParentheses(string s) {
//        int ans=0;
//        int cnt=1;
//        int n=s.size();
//        for(int i=0;i<n;i++)
//        {
//             char c=s[i];
//             if(c=='(') cnt++;
//             else if(c==')') cnt--;
//             if(cnt<0) continue;
//             if(cnt%2==0) ans=max(ans,i);
//        } 
//        return ans;
//     }
// };
