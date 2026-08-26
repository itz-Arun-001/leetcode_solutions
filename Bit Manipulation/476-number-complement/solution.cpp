class Solution {
public:
    int findComplement(int num) {
        int x=num;
        int temp=0;
        while(x>0)
        {
            temp=(temp<<1)|1;
            
            x>>=1;
        }
        return num^temp;
        
    }
};
