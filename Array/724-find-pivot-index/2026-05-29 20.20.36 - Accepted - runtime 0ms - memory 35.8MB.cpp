/*class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size(),r=0,l=0;
        vector<int >lsum(n,0),rsum(n,0);

        for(int i=0;i<n;i++)
        {
            l+=nums[i];
            r+=nums[n-i-1];
            lsum[i]=l;
            rsum[n-i-1]=r;
        }
        for(int i=0;i<n;i++)
        {
            if(lsum[i]==rsum[i]) return i;
        }
        return -1;
        
    }
};
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int r=0,l=0,tot=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++)
        {
            r=tot-l-nums[i];
            if(r==l)
                return i;
            l+=nums[i];
        }
        return -1;

    }
};