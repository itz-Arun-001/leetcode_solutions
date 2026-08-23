class Solution {
public:
    int gives(int n)
    {
        if(n==0) return 0;
        int s=0;
        while(n>0)
        {
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int pro(int n)
    {
        int p=1;
        while(n>0)
        {
            p*=n%10;
            n/=10;
        }
        return p;
    }
    bool checkDivisibility(int n) {
        int a=gives(n);
        int b=pro(n);
        return n%(a+b)==0;
        
    }
};
