class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>st;
        vector<int>ans(t.size(),0);
        for(int i=0;i<t.size();i++)
        {
            while(!st.empty()&&t[st.top()]<t[i])
            {
                 int ptemp=st.top();
               st.pop();
                ans[ptemp]=i-ptemp;


            }
            st.push(i);

        }
        return ans;
        
    }
};