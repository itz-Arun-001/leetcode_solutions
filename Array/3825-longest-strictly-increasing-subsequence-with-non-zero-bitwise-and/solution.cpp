class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        //int cnt=0,maxans=INT_MIN,prev=INT_MIN;
        int maxans=0;
        for(int i=0;i<32;i++)
        {
            vector<int>temp;
           // prev=INT_MIN;
           // cnt=0;
            for(int x:nums)
            {
                if((x&(1<<i))==0)
                {
                   // cnt++;
                     //prev=x;
                     continue;

                }
                auto it=lower_bound(temp.begin(),temp.end(),x);
                if(it==temp.end())
                {
                    temp.push_back(x);
                }
                else{
                    *it=x;
                }
               
            }
            maxans=max(maxans,(int)temp.size());

        }   
        return maxans;
    }
};
