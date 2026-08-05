class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>>rb(n,vector<char>(m,'.'));
        for (int i=0;i<m;i++)
        {
            int x=n-1;
            for (int j=n-1;j>=0;j--) {
                if (box[i][j]=='#') {
                    swap(box[i][j], box[i][x]);
                    x--;
                }
                 else if (box[i][j]=='*') {
                    x=j-1;
                }
            }
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                rb[j][m -1-i]=box[i][j];
            }
        }
        return rb;
    }
};