class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> need(26, 0);

        for (char c : licensePlate) {
            if (isalpha(c))
                need[tolower(c) - 'a']++;
        }

        string ans = "";

        for (string& word : words) {
            vector<int> freq(26, 0);

            for (char c : word)
                freq[c - 'a']++;

            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < need[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok && (ans.empty() || word.size() < ans.size()))
                ans = word;
        }

        return ans;
    }
};
