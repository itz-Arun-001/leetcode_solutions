class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int x=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            arr[i]=min(arr[i],x+1);
            if(arr[i]==x+1) x++;
        }
        return arr[n-1];
        
    }
};
