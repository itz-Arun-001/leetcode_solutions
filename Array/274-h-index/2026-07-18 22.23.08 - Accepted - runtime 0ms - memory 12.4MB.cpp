class Solution {
public:
    int hIndex(vector<int>& n) {
        sort(n.begin(),n.end(),greater<int>());
        int hidx=0;
        for(int i=0;i<n.size();i++)
        {
            if(n[i]>=i+1)
             hidx=i+1;
            else break;
        }
        return hidx;
        
    }
};