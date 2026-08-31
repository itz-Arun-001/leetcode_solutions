class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0"; 
       /* if(num<0)
        {
            num=!num;
            num+=1;
        }*/

        unsigned int n=num;
        string s="";
        while(n>0)
        {
            int cnt=0;
            int temp=0;
            while (cnt < 4) {
                temp = temp | ((n & 1) << cnt);
                n >>= 1;
                cnt++;
            }
            if(temp<=9)
                 s+='0'+temp;
            else s+=(temp-10)+'a';
        }

        reverse(s.begin(),s.end());
        return s;
        
    }
};
