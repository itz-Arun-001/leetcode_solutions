/*class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt = 0;
        while (tickets[k] > 0) {
            for (int i = 0; i < tickets.size(); i++) {
                tickets[i]--;
                cnt++;
                if(i==k&&tickets[i]==0)  break;
            }
        }
        return cnt;
    }
};
*/


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt = 0;
        for(int i=0;i<tickets.size();i++)
        {
            if(i<=k)
              cnt+=min(tickets[i],tickets[k]);
            else cnt+=min(tickets[i],tickets[k]-1);
        }
        return cnt;
    }
};