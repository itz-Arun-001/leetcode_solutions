class Solution {
public:
    int cnt=0;
    int minChanges(string s) {
        int n=s.size();
        for(int i=0;i<n-1;i+=2)
        {
            if(s[i]!=s[i+1])
                cnt++;
            
        }
        return cnt;
    }
};
/*class Solution {
public:
    int cnt=0;
    void help(string s)
    {
        int n=s.size();
        if(n<=1)return;
        if(n==2){
            if(s[0]!=s[1])
                cnt++;
            return;
        }
        help(s.substr(0,n/2));
        help(s.substr(n/2,n-n/2));
        

    }
    int minChanges(string s) {
        int n=s.size();
        help(s);
        return cnt;
    }
};*/
