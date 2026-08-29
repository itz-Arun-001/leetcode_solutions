class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt=0;
        /*for(int i=left;i<=right;i++)
        {
            ans^=i;
        }*/
        while(left<right)
        {
            cnt++;
            left>>=1;
            right>>=1;

        }
        return left<<=cnt;
    }
};
