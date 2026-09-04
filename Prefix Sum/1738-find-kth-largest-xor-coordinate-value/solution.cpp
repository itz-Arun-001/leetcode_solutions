class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        vector<vector<int>>prefix(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
             {
                prefix[i+1][j+1]=matrix[i][j]^prefix[i][j+1]^prefix[i+1][j]^prefix[i][j];
                ans.push_back(prefix[i+1][j+1]);
             }
        }
        //sort(ans.rbegin(),ans.rend());
        nth_element(ans.begin(),ans.begin()+k-1,ans.end(),greater<int>());
        return ans[k-1];

    }
};
