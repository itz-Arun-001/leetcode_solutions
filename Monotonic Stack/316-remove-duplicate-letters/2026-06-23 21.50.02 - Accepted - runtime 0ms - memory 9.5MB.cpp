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
        string res="";
        for (auto c : s) {
            freq[c - 'a']++;
        }
        for (char c : s) {
            freq[c - 'a']--;

            if (visited[c - 'a'])
                continue;

            while (!res.empty() && res.back() > c && freq[res.back() - 'a'] > 0) {
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(c);
            visited[c - 'a'] = true;
        }
        
      /*  while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());*/
        return res;
    }
};