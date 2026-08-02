class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<char> str(s.begin(), s.end());
        string t = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                st.push(i);
            } else if (str[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    str[i] = '$';
                }
            } else
                continue;
        }
        while(!st.empty())
        {
           str[st.top()]='$';
           st.pop(); 
        }
        string res="";
        for(int i=0;i<str.size();i++)
        {
          if(str[i]!='$')
          {
            res+=str[i];
          } 
          else continue; 
     
        }
        return res;
    }
};