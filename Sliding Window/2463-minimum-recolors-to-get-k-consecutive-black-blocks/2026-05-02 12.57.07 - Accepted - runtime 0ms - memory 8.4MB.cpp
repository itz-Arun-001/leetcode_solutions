class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int ans=INT_MAX,temp=0;
        for(int i=0;i<k;i++)
        {
            if(blocks[i]=='W')
                temp++;
        }
        ans=min(ans,temp);
        for(int i=k;i<n;i++)
        {
            if(blocks[i]=='W') temp++;

            if(blocks[i-k]=='W')    temp--;
            ans=min(ans,temp);
        }
        return ans;

        
    }
};