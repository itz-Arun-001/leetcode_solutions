class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int l = 1,r = n;
        while (l<=r) {
            if (k>1) {
                if (k%2==1)
                    ans.push_back(l++);
                else
                    ans.push_back(r--);
                k--;
            } else {
                ans.push_back(l++);
            }
        }

        return ans;
    }
};