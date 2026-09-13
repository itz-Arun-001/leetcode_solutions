class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map<pair<int,int>,int>freq;
        int n=img1.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 if(img1[i][j]==0) continue;
                for(int a=0;a<n;a++)
                {
                  for(int b=0;b<n;b++)
                  {
                     if(img2[a][b]==0) continue;
                      freq[{a-i,b-j}]++;
                      mx=max(freq[{a-i,b-j}],mx);
                  } 
                }
            }
        }
        return mx!=INT_MIN?mx:0;
    }
};
