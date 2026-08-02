class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt=1;
        vector<int>un;
        long long n2=0,n3=0,n5=0;
       long long p2=0,p3=0,p5=0;
        un.push_back(1);
        while(cnt<n)
        {
            n2=un[p2]*2;
            n3=un[p3]*3;
            n5=un[p5]*5;
           long long x=min(n2,min(n3,n5));
            if(x==n2) p2++;
            if(x==n3) p3++;
            if(x==n5) p5++;
            un.push_back(x);
            cnt++;
        }
        return un[un.size()-1];
        
    }
};