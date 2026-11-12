class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int left=0,right=n-1;
        int ans=INT_MAX;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]<=arr[i])
                left=i;
            else break;
        }
        if(left==n-1) return 0;
        for(int i=n-1;i>0;i--)
        {
            if(arr[i-1]<=arr[i])
                right=i-1;
            else break;
        }
        ans=min(n-left-1,right);
        int i=0,j=right;
        while(i<=left && j<n)
        {
            if(arr[i]<=arr[j])
            {
                ans=min(ans,j-i-1);
                i++;
            }
            else j++;
        }
        return ans;
    }
};
