class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int cnt=0;
        int i=0,j=0,m=players.size(),n=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(i<m&&j<n)
        {
            if(players[i]<=trainers[j]){
                 cnt++;
                 i++;
                 j++;
            }
            else j++;
        }
        return cnt;
    }
};
