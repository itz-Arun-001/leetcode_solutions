class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int leftSmall = 0, leftLarge = 0;
            int rightSmall = 0, rightLarge = 0;

            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i])
                    leftSmall++;
                else
                    leftLarge++;
            }

            for (int j = i + 1; j < n; j++) {
                if (rating[j] < rating[i])
                    rightSmall++;
                else
                    rightLarge++;
            }

            ans += leftSmall * rightLarge;
            ans += leftLarge * rightSmall;
        }

        return ans;
    }
};