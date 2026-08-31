class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        while(a>0||b>0||c>0)
        {
            int x=a&1;
            int y=b&1;
            int z=c&1;
           if(z==0)
            {
                if(x==1)
                    flips++;
                if(y==1)
                    flips++;
            }
            else{
                if(x==0&&y==0)
                    flips++;
            }
            a>>=1;
            b>>=1;
            c>>=1;

        }
        return flips;
        
    }
};
