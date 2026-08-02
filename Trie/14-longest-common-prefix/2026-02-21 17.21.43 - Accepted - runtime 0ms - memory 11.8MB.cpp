class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        int n = strs.size();
        if(n == 0) return "";

        int m = strs[0].size();

        for(int j = 0; j < m; j++)
        {
            char ch = strs[0][j];

            for(int i = 1; i < n; i++)
            {
                if( strs[i][j] != ch)
                    return res;   // stop immediately
            }

            res.push_back(ch);
        }

        return res;
    }
};