class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diffarr(1001,0);
        for(auto a:trips)
        {
            int pas=a[0];
            int from=a[1];
            int to=a[2];
            diffarr[from]+=pas;
            diffarr[to]-=pas;
        }
        int cpas=0;
        for(int i=0;i<diffarr.size();i++)
        {
            cpas+=diffarr[i];
            if(cpas>capacity) return false;
        }
        return true;
    }
};