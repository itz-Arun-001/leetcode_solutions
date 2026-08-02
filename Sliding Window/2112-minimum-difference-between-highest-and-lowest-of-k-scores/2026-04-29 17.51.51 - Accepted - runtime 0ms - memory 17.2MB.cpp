class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int mind=INT_MAX;
        int n=nums.size();
        int dif=0;
        sort(nums.begin(),nums.end());
   //     int h=INT_MIN;
     //   int l=INT_MAX;

        for(int i=0;i<=n-k;i++)
        {
            dif=nums[i+k-1]-nums[i];
            mind=min(mind,dif);
        }
        return mind;


        
    }
};