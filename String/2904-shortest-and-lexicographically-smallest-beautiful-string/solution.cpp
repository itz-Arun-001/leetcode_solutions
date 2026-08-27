class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int len=0,blen=INT_MAX;
        string a="";
        int cnt=0;
        int j=0,n=s.size();
          string temp="";
        for(int i=0;i<n;i++)
        {

            if(s[i]=='1') cnt++;
             while(cnt>k)
            {
                if(s[j]=='1')
                {
                    cnt--;
                }
                j++;
            }
            while(cnt==k&&s[j]=='0') j++;
            if(cnt==k){
                 len=i-j+1;
            
               if(len<blen)
               {
                temp=s.substr(j,len);
                blen=len;
                
               }
              else if(blen==len)
               {
                if(temp>s.substr(j,len))
                {
                    temp=s.substr(j,len);
                }
               }
            }

        }
        return  temp;
    }
};
