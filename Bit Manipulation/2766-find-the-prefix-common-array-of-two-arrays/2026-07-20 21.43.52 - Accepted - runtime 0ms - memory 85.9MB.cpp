/*class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, pair<int, int>> mp;
        vector<bool> counted(A.size() + 1, false);
        for (int i = 0; i < A.size(); i++) {
            mp[A[i]].first = i;
            mp[B[i]].second = i;
        }
        vector<int> ans(A.size(), 0);
        int cnt = 0;
        for (int i = 0; i < A.size(); i++) {
            if (mp[A[i]].first <= i && mp[A[i]].second <= i && !counted[A[i]]) {

                cnt++;
                counted[A[i]] = true;
            }
            if (A[i] != B[i] && mp[B[i]].first <= i && mp[B[i]].second <= i &&
                !counted[B[i]]) {
                cnt++;
                counted[B[i]] = true;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans(n);

        int common = 0;

        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2)
                common++;

            freq[B[i]]++;
            if (freq[B[i]] == 2)
                common++;

            ans[i] = common;
        }

        return ans;
    }
};