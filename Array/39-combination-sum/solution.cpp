class Solution {
public:
vector<vector<int>>ans;
    void help(vector<int>& can,int &t,int idx,vector<int>& temp,int &sum)
    {
        if(sum>t) return;
        if(sum==t)
        {
            ans.push_back(temp);
            return;
        }
        int n=can.size();
        for(int i=idx;i<n;i++)
        {
           //while(find(can.begin(), can.end(), t - sum) != can.end())
            //{
                sum+=can[i];
                temp.push_back(can[i]);
                help(can,t,i,temp,sum);
            //}
            temp.pop_back();
            sum-=can[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        int s=0;
        help(candidates,target,0,temp,s);
        return ans;
    }
};
