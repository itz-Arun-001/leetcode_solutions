class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min=prices[0];
        int profit=0;
        int max=0;
        int n=prices.size();
        //int max=0; 
        bool hold=0;
        for(int i=1;i<n;i++)
        {
            if(prices[i]>prices[i-1])
            {
                profit+=prices[i]-prices[i-1];
            }

                }
        return profit;

    }
};
        
