class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;
        int cnt=0;
        while(n>0)
        {
            cnt++;
            n>>=1;
        }
        return pow(2,cnt);
    }
};
