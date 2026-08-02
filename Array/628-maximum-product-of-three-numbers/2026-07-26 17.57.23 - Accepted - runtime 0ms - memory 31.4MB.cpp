class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        int p=INT_MAX,q=INT_MAX;
        for(int x: nums )
        {
            if(x<p){
                q=p;
                p=x;
            }
            else if(x<q) q=x;
            if(x>a)
            {
                c=b;
                b=a;
                a=x;
            }
           else if(x>b)
           {
                c=b;
                b=x;

           }
           else if(x>c) c=x;
        }
        return max(a*(b*c),(p*q)*a);
        //return c;
        
    }
};