class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a=-1,b=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(a<=nums[i])
            {
                b=a;
                a=nums[i];

            }
            else if(b<nums[i]) b=nums[i];
        }
        return (a-1)*(b-1);
    }
};