class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0)
        {
            return {0};
        }
        vector<int>ans={0,1};
        for(int i=1;i<n;i++)
        {
            int m=ans.size();
            for(int j=m-1;j>=0;j--)
            {
                ans.push_back(ans[j]|(1<<i));
            }
        }
        return ans;
        
    }
};
