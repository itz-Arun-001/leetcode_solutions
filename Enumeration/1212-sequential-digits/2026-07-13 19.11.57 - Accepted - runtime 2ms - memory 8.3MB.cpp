class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string key = "123456789";
        string s1 = to_string(low);
        string s2 = to_string(high);

        int n1 = s1.size(), n2 = s2.size();

        for (int len = n1; len <= n2; len++) {
            for (int i = 0; i <= 9 - len; i++) {
                int num = stoi(key.substr(i, len));

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};