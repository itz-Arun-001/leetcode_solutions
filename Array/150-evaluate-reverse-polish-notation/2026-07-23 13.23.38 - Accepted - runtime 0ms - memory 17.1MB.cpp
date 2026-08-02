class Solution {
public:
    int evalRPN(vector<string>& str) {
        stack<int> st;
        for (auto s : str) {
            if (s != "+" && s != "-" && s != "*" && s != "/")
                st.push(stoi(s));
            else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (s == "+") {
                    st.push(a + b);

                } else if (s == "-")
                    st.push(b - a);

                else if (s == "*")
                    st.push(a * b);
                else if (s == "/")
                    st.push(b / a);
            }
        }
        return st.top();
    }
};