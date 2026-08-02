class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        int low=((n+1)/2)-1;
        int high=n-1;
       for(int i=0;i<n;i++)
       {
        if(i%2==0)
        {
            nums[i]=temp[low--];
        }
        else
        {
            nums[i]=temp[high--];
        }
       }
    }
};