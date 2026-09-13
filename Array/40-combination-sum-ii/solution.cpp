/*class Solution {
public:
    set<vector<int>>st;
    void help(int idx,vector<int>& can,int& t,int &sum,vector<int> &temp,int & size)
    {
        if(sum>t) return;
        if(sum==t)
        {
            st.insert(temp);
            return;
        }
        for(int i=idx;i<size;i++)
        {
            temp.push_back(can[i]);
            sum+=can[i];   
            help(i+1,can,t,sum,temp,size);
            temp.pop_back();
            sum-=can[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int>temp;
        int n=candidates.size(),s=0;
        vector<vector<int>>ans;
        help(0,candidates,target,s,temp,n);
        for(auto s:st)
        {
            ans.push_back(s);
        }
        return ans;
    }
};*/

class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>& can,int t,int idx,int &size,vector<int>& temp,int &sum)
    {
        if(t==sum)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<size;i++)
        {
            if(i>idx&&can[i]==can[i-1])
            {
                continue;
            }
           if(sum+can[i]>t) break;
           sum+=can[i];
            temp.push_back(can[i]);
            help(can,t,i+1,size,temp,sum);
            temp.pop_back();
            sum-=can[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        int n=candidates.size(),s=0;
        help(candidates,target,0,n,temp,s);
        return ans;
    }
};
