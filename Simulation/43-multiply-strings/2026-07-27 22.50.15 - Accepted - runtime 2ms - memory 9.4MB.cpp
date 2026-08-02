class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        vector<int> ans(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; j--) {
                int y = num2[j] - '0';
                int sum = ans[i + j + 1] + x * y;
                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }
        string res = "";
        int i = 0;
        while (i < ans.size() && ans[i] == 0)
            i++;
        while (i < ans.size())
            res += ans[i++] + '0';
        return res;
    }
};