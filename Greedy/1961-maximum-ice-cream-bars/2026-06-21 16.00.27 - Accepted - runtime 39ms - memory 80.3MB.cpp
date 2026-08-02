class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int x=0;
        int sum=0;
        for(int i=0;i<costs.size();i++)
        {
            if(costs[i]+sum<=coins)
            {         sum+=costs[i];
            x++;
            }
            else break;
        }
        return x;
        
    }
};