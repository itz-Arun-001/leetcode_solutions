/*        int GCD(int a, int b)
        {
            if (b == 0)
            {
                return a;
            }
         return GCD(b, a % b);
    }
int LCM(int a, int b) {
    if (a == 0 || b == 0)
        return 0;
    return (a / GCD(a, b)) * b;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}*/
class Solution {
public:
    int maxLength(vector<int>& nums){
        int n=nums.size();
        long long p=1;
        int l=0,g=0,c=0;
        for(int i=0;i<n;i++)
        {
            p=1;
            l=1;
            g=0;
            for(int j=i;j<n;j++)
            {
                if(p<LLONG_MAX/nums[j]){
                p=p*nums[j];}
                else break;
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                if(p==g*l)  c=max(c,j-i+1);
            }

        }
        return c;
}
};
/*
        int GCD(int a, int b)
        {
            if (b == 0)
            {
                return a;
            }
         return GCD(b, a % b);
    }
int LCM(int a, int b) {
    if (a == 0 || b == 0)
        return 0;
    return (a / GCD(a, b)) * b;
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
class Solution {
public:
    int maxLength(vector<int>& nums){
        int n=nums.size();
        long long p=1;
        int l=0,g=0,c=0,l=0;
        for(int i=0;i<n;i++)
        {

        }
*/