class Solution {
    public int longestSubsequence(int[] nums) {
        int temp=0;
        int zc=0;
        for(int n:nums)
        {
            temp^=n;
            if(n==0) zc++;
        }
        if(temp!=0) return nums.length;
        int n=nums.length;
        if(zc==n) return 0;
        return n-1;
    }
}
