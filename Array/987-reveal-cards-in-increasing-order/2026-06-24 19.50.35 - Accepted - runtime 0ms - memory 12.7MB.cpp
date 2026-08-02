class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int>ans(deck.size(),0);
        queue<int>q;
        for(int i=0;i<deck.size();i++)
        {
            q.push(i);
        }
        int i=0;
        while(!q.empty())
        {
            int pos=q.front();
            q.pop();
            ans[pos]=deck[i++];
            if(!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
            
        }
        return ans;
        
    }
};