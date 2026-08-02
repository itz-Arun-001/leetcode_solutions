class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int maxp = INT_MIN;
        int a=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            a+=i*nums[i];
            sum+=nums[i];

        }
        maxp=max(maxp,a);
        for(int i=1;i<n;i++)
        {
            a+=sum-(n*nums[n-i]);
            maxp=max(maxp,a);
        }
        return maxp;

}
}
;