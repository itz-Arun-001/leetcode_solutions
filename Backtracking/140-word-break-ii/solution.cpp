/*class Solution {
public:
    vector<vector<string>> wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<vector<string>>ans;
        unordered_set<string>list(wordDict.begin(),wordDict.end());
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&list.count(s.substr(j,i-j)))
                {
                    dp[i]=true;
                    ans.push_back(s.substr(j,i-j));
                    break;
                }
            }
        }
        return ans;

    }
};*/

class Solution {
public:
    vector<string> ans;
    void help(string& s, vector<string>& temp, int idx,
              unordered_set<string>& st) {
        if (idx == s.size()) {
            string str = "";
            for (int i = 0; i < temp.size(); i++) {
                if (i > 0)
                    str += " ";
                str += temp[i];
            }
            ans.push_back(str);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            string word = s.substr(idx, i - idx + 1);
            if (st.find(word) != st.end()) {
                temp.push_back(word);
                help(s, temp, i + 1, st);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for (string word : wordDict)
            st.insert(word);
        vector<string> temp;
        help(s, temp, 0, st);
        return ans;
    }
};
