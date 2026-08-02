class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int psum=0;
        int l=0;
        int count=0;
        unordered_map<int,int> freq;
        freq[0]=1;
        for(int i=0;i<n;i++)
        {
            psum+=nums[i];
            int rem=psum%k;
            if(rem<0)
            {
                rem+=k;

            }
            count+=freq[rem];
            freq[rem]++;
        }
        return count;
        
    }
};