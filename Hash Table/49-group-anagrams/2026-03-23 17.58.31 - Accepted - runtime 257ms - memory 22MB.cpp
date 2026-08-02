class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        vector<string> copy = strs;
        vector<string> temp;
        vector<bool> visited(n, false);   // ✅ separate visited array

        for(int i = 0; i < n; i++)
        {
            sort(copy[i].begin(), copy[i].end());
        }

        string key;

        for(int i = 0; i < n; i++)
        {
            if(visited[i]) continue;   // ✅ skip if already grouped

            temp.clear();
            key = copy[i];
            temp.push_back(strs[i]);
            visited[i] = true;

            for(int j = i + 1; j < n; j++)
            {
                if(!visited[j] && key == copy[j])
                {
                    temp.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};