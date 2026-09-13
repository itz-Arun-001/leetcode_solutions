class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>& temp,int& k,int& n,int idx,int &sum)
    {
        if(sum==n&&temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        if(sum>n) return;
        if(temp.size()>k) return;
        for(int i=idx;i<=9;i++)
        {
            sum+=i;
            temp.push_back(i);
            help(temp,k,n,i+1,sum);
            sum-=i;
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        int s=0;
        help(temp,k,n,1,s);
        return ans;
    }
};
