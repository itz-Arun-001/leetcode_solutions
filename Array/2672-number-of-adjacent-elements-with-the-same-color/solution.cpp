class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& qu) {
        int s=qu.size();
        vector<int>sol(s,0);
        vector<int>color(n,0);
        int ans=0;
        for(int i=0;i<s;i++)
        {
            int pos = qu[i][0];
            int c = qu[i][1];
           if (pos > 0) {
                if (color[pos] != 0 && color[pos] == color[pos - 1])
                    ans--;
            }

            if (pos < n - 1) {
                if (color[pos] != 0 && color[pos] == color[pos + 1])
                    ans--;
            }
            color[pos]=c;
             if (pos > 0) {
                if (color[pos] != 0 && color[pos] == color[pos - 1])
                    ans++;
            }
            if (pos < n - 1) {
                if (color[pos] != 0 && color[pos] == color[pos + 1])
                    ans++;
            }
            sol[i]=ans;
        }
        return sol;
        
    }
};
