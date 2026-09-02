class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0,mask=0;
        unordered_set<int> st;
        for(int i=31;i>=0;i--)
        {
            mask=mask|(1<<i);
            st.clear();
            for(int n: nums)
            {
                st.insert(n&mask);
            }
            int pos=ans|(1<<i);
            for(int p:st)
            {
                int req=pos^p;
                if(st.find(req)!=st.end())
                {
                    ans=pos;
                    break;
                }
            }
        }
        return ans;
        
    }
};
