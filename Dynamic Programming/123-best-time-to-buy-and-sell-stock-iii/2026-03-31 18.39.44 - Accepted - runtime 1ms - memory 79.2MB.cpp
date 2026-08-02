class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int fb=INT_MAX,fs=0,sb=INT_MAX,ss=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            fb=min(fb,prices[i]);
            fs=max(fs,prices[i]-fb);
            sb=min(sb,prices[i]-fs);
            ss=max(ss,prices[i]-sb);
        }
        return ss;
    }
};