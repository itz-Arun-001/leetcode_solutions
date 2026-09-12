class Solution {
public:
    vector<string> ans;
    string mp[10] = {
        "", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
    void help(string& digits, int idx, string& temp) {
        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }
        string letters = mp[digits[idx] - '0'];
        for (char ch : letters) {
            temp.push_back(ch);
            help(digits, idx + 1, temp);
            temp.pop_back(); 
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        string temp;
        help(digits, 0, temp);
        return ans;
    }
};
