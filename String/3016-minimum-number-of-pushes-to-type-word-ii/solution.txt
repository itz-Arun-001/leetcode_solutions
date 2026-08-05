class Solution {
public:
    /*static bool cmp(const int& a,const int& b)
    {
        return a>b;
    }*/
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        for(int i=0;i<word.size();i++)
        {
            mp[word[i]-'a']++;
        }
        //sort(mp.begin(),mp.end(),cmp);
        //sort(mp.begin(), mp.end(), greater<int>());
        sort(mp.rbegin(), mp.rend());
        int cnt=0;int ans=0;
        for(int& x:mp)
        {
          /*  if(cnt<8) ans+=x*1;
            else if(cnt<16) ans+=x*2;
            else if(cnt<24) ans+=x*3;
            else ans+=x*4;
            cnt++;
            */
            ans+=x*(cnt/8+1);
            cnt++;
        }
        return ans;
    }
};