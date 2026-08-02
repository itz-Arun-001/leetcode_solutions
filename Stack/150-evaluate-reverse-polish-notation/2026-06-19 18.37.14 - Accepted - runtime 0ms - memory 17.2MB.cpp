class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> st;
        for (string s : t) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                if (s == "+") {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(a + b);
                } else if (s == "-") {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b - a);
                } else if (s == "*") {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(a * b);

                } else {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    st.push(b / a);
                }
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};