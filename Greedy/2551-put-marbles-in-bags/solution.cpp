class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k==weights.size()) return 0;
        vector<int>temp;
        int n=weights.size();
        for(int i=0;i<n-1;i++)
        {
            temp.push_back(weights[i]+weights[i+1]);
        }
        sort(temp.begin(),temp.end());
        long long minv=accumulate(temp.begin(),temp.begin()+k-1,0LL);
        long long maxv=accumulate(temp.end()-k+1,temp.end(),0LL);
        return maxv-minv;

        
    }
};
