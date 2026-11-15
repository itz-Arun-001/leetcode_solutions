class Solution {
public:
    static bool cmp(const vector<int>& job,const int val)
    {
        return job[0]<val;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n=startTime.size();
        for(int i=0;i<n;i++)
        {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int st=jobs[i][0];
            int end=jobs[i][1];
            int  prof=jobs[i][2];
            int j=lower_bound(jobs.begin(),jobs.end(),end,cmp)-jobs.begin();
            dp[i]=max(dp[j]+prof,dp[i+1]);
        }
        return dp[0];
    }
};
