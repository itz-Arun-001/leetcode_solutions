class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        vector<bool> visit(26,false);
        vector<int>li(26,-1);
        int i=-1;
        for(int k=0;k<s.size();k++)
            li[s[k]-'a']=k;
        
        for(char c:s)
            {
                i++;
                if(visit[c-'a'])
                {
                    continue;
                    
                }
                while(!st.empty()&&st.top()>c&&li[st.top()-'a']>i){
                    visit[st.top()-'a']= false;
                    st.pop();
                }
                st.push(c);
                visit[c-'a']=true;
                
            }
        s="";
        while(!st.empty())
            {
                s+=st.top();
                st.pop();
            }
         reverse(s.begin(),s.end());
    return s;
    }
};