class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       /* int high=0;
        vector<int>alt;
        alt.push_back(0);
        int j=0;
        for(int i=0;i<gain.size()-1;i++)
        {
           alt.push_back(alt[j]+gain[i]);
           j++;
            high=max(high,alt[j]);
        }
       // high=max(high,alt[alt.size()-1]);*/
       int high=0;
       int cur=0;
       for(auto i:gain)
       {
        cur+=i;
        high=max(cur,high);
       }
        return high;
        
    }
};