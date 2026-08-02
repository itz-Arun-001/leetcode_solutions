class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long sum=0;
        long long ans=0;
        for (char c : s) {
            long long a=c-'0';
            if (a!= 0) {
                
              ans = ans * 10 + a;
              sum+=a;

                
            }
        }
        return ans*sum;
    }
};