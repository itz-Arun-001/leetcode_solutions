class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long sum=0;
        long long ans=0;
        long long place=1;
       /* for (char c : s) {
            long long a=c-'0';
            if (a!= 0) {
                
              ans = ans * 10 + a;
              sum+=a;

                
            }
        }*/
        while(n>0)
        {
            long long a=n%10;
            n/=10;
            if (a!= 0) {
                
            ans += a * place;
                sum += a;
                place *= 10;

                
            }
        }
        return ans*sum;
    }
};