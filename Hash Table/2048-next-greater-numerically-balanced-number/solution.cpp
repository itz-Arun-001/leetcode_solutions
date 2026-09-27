class Solution {
public:
    int ans = INT_MAX;
    void permute(vector<int>& temp,vector<int>& freq,int idx,long long curr,int n) {
        if (idx==temp.size()) {
            if (curr>n)
                ans =min(ans,(int)curr);
            return;
        }
        for(int d =1;d<=7;d++) {
            if (freq[d]>0) {
                freq[d]--;
                permute(temp,freq,idx+1,curr*10+d,n);
                freq[d]++;
            }
        }
    }
        void help(int d,int n,vector<int>& temp) {
            if (temp.size()>7)
                return;
        if (d>7) {
            if (temp.empty())
                return;
            vector<int> freq(8,0);
            for (int x :temp)
                freq[x]++;
            permute(temp,freq,0,0,n);
            return;
        }
        help(d+1,n,temp);
        for(int i=0; i<d;i++)
            temp.push_back(d);
        help(d+1,n,temp);
        for (int i=0;i<d;i++)
            temp.pop_back();
    }
    int nextBeautifulNumber(int n) {
        vector<int>temp;
        help(1,n,temp);
        return ans;
    }
};
