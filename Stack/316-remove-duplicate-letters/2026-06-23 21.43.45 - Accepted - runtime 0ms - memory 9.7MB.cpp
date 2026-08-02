/*class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        // stack<char>st;
        for (auto c : s) {
            freq[c - 'a']++;
        }
        string ans = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                ans.push_back(i + 'a');
                freq[i] = -1;
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, 0);
        stack<char> st;
        for (auto c : s) {
            freq[c - 'a']++;
        }
        for (char c : s) {
            freq[c - 'a']--;

            if (visited[c - 'a'])
                continue;

            while (!st.empty() && st.top() > c && freq[st.top() - 'a'] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[c - 'a'] = true;
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