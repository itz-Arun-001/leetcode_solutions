/*class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string t = "";
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '1' && s[i] <= '9') {
                x = (x * 10) + (s[i] - '0');
            } else if (s[i] == '[')
                continue;
            else if (s[i] >= 'a' && s[i] <= 'z') {
                while (x > 0) {
                    t += "s[i]";
                    x--;

                }
                st.push(t)            }
            else {
                t="";
            }
        }
    }
};*/
class Solution {
public:
    string decodeString(string s) {
        stack<string>sst;
        stack<int>ist;
        int num=0;
        string t="";
        for(auto c: s)
        {
            if(c>='0'&&c<='9')
            {
                num=(num*10)+(c-'0');
            }
            else if(c=='['){
                ist.push(num);
                num=0;
                sst.push(t);
                t="";
            }
            else if(c==']')
            {
                int x=ist.top();
                ist.pop();
                string st=sst.top();
                sst.pop();
                string temp="";
                for(int i=0;i<x;i++)
                {
                    temp+=t;
                }
                t=st+temp;
            }
            else{
                t+=c;
            }
        }
        return t;
    }
};