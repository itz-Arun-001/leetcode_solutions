/*class Solution {
public:
    int maxsize=-1;
    void help(vector<int>& nums,int andval,int idx,int n,int size)
    {   
        if(size>0&&andval>0)
        {
            maxsize=max(maxsize,size);
        }
        for(int i=idx;i<n;i++)
        {
            int temp;
            if(size==0)
            {
                temp=nums[i];
            }
            else{
                temp=andval&nums[i];
            }
        help(nums,temp,i+1,n,size+1);
        }

        
        
    }
    int largestCombination(vector<int>& candidates) {
        help(candidates,0,0,candidates.size(),0);
        return maxsize;
    }
};*/
class Solution {
public:
 int largestCombination(vector<int>& candidates) {
    vector<int>cnt(32,0);
    //int ans=0;
    for(int i=32-1;i>=0;i--)
    {
       // int cnt=0;
        for(int j=0;j<candidates.size();j++)
        {
            if(candidates[j] & (1 << i))
            {
                cnt[i]++;
            }
        }
        //ans=max(ans,cnt);

    }
    int mx=*max_element(cnt.begin(),cnt.end());
    return mx;
   // return ans;
 }
};
