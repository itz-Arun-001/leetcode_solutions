class Solution {
public:
    int bestClosingTime(string c) {
       long long pen =count(c.begin(),c.end(),'Y');

        long long mpen=pen;
        int idx=0;
        int n=c.size();
        for(int i=0;i<n;i++)
        {
           
            if(c[i]=='Y') pen--;
            else pen++;
             if(pen<mpen){
                mpen=pen;
                idx=i+1;
            }
         

        }
        return idx;
    }
};