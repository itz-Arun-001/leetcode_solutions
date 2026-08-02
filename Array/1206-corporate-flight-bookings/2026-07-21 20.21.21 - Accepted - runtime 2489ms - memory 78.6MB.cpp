class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
        for(auto a:bookings)
        {
            int first=a[0];
            int last=a[1];
            while(first<=last)
            {
                ans[first-1]+=a[2];
                first++;
            }
        }
        return ans;
        
    }
};