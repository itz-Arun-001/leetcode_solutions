class Solution {
public:
    int maxProduct(int n) {
        int fm=-1,sm=-1;
        while(n>0){
            int x=n%10;
            n/=10;
            if(fm<=x){
                sm=fm;
                fm=x;
            }
            else if(sm<=x) sm=x;
            
        }
        return fm*sm;
        
    }
};