class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xr=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            xr^=nums[i];
        }
        if(xr==0) return true;
        else if(xr!=0&&n%2==1) return false;
        return true;
    }
};
