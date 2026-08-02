class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        for(auto a:bookings)
        {
            int first=a[0];
            int last=a[1];
            ans[first-1]+=a[2];
            if(last<n) ans[last]-=a[2];
        }
        for(int i=1;i<n;i++)
            ans[i]+=ans[i-1];
        return ans;
        
    }
};