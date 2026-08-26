/*class Solution {
public:
    bool isPowerOfTwo(int n) {
            if(n<=0) return false;
            int cnt=0;
            while(n!=0)
            {
                cnt+=n&1;
                n>>=1;
                if(cnt>1) return false;
            }
            return true;
    }
};*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        return (n&(n-1))==0;
    }
};
