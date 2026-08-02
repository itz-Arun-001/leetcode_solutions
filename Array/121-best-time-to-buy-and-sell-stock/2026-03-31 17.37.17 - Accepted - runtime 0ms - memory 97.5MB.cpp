class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum=prices[0];
        int profit=0;
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            minimum=min(minimum,prices[i]);
            int cur=prices[i]-minimum;
            profit=max(profit,cur);
        }
        return profit;

    }
};