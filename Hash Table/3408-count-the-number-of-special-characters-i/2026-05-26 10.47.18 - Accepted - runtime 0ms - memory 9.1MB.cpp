class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        array<int, 26> small = {0};
        array<int, 26> large = {0};
        for (int i = 0; i < n; i++) {
            if (word[i] >= 'a' && word[i] <= 'z')
                small[word[i] - 'a']++;
            else
                large[word[i] - 'A']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (small[i] > 0 && large[i] > 0)
                ans++;
        }
        return ans;
    }
};