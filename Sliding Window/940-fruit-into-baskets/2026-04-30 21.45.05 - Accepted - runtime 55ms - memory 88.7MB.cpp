class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int n=fruits.size();
        int maxf=INT_MIN;
        int l=0;
        for(int r=0;r<n;r++)
        {
            mp[fruits[r]]++;
            if(mp.size()>2)
            {
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            maxf=max(maxf,r-l+1);
        }
        return maxf;
    }
};