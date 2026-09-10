class Solution {
public:
   void solve(int& m,int idx,vector<vector<int>>& requests,vector<int>& arr,int& ans,int cnt)
   {
    if(idx==m)
    {
        bool flag=true;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=0){
                flag=false;
                break;
                }
        }
        if(flag){
            ans=max(ans,cnt);
           
        }
         return;
    }
    arr[requests[idx][0]]--;
    arr[requests[idx][1]]++;
    solve(m,idx+1,requests,arr,ans,cnt+1);
     arr[requests[idx][0]]++;
    arr[requests[idx][1]]--;
    solve(m,idx+1,requests,arr,ans,cnt);
   }
    int maximumRequests(int n, vector<vector<int>>& requests) {
         vector<int>arr(n,0);
         int ans=0,cnt=0,m=requests.size();
        solve(m,0,requests,arr,ans,cnt);
        return ans;
    }
};
