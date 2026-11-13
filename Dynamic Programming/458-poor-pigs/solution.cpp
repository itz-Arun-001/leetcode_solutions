class Solution {
public:
    int poorPigs(int buckets, int mTD, int mTT) {
        int t=mTT/mTD;
        int p=0;
        for(int i=1;i<buckets;i*=(t+1))
        {
            p++;
        }
        return p;
    }
};

/*class Solution {
public:
    int poorPigs(int buckets, int mTD, int mTT) {
        int t=mTT/mTD;
        int p;
        p=ceil(log(buckets)/log(t+1)-1e-12);
        return p;
        
    }
};*/
