class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int count=0;
        unordered_map<int,int>freq;
        freq[0]=1;
        int psum=0;
        for(int i=0;i<n;i++)
        {
            psum+=nums[i];
            int p=psum-k;
            if(freq.count(p)) count+=freq[p];
            freq[psum]++;
        }
        return count;
        
    }
};