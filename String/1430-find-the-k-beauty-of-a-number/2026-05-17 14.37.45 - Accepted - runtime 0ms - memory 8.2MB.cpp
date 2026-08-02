/*class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s= to_string(num);
        int n=s.size();
        int sum=0;

        for(int i=0;i<k;i++)
        {
            int p=stoi(s.substr(i,k));
            sum+=p;
        }
        int c=0;
        if(sum!=0&&num%summ==0)
            c++;
        for(int i=k;i<n;i++)
        {
            int p=stoi(s[i]);
            sum+=p;
            p=stoi(s[i-k]);
            sum-=p;
            if(sum!=0&&num%sum==0)
                 c++;
        }
        return c;
    }
};
*/

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s= to_string(num);
        int n=s.size();
        int c=0;
        for(int i=0;i<n-k+1;i++)
        {
            int p=stoi(s.substr(i,k));
            if(p!=0&&num%p==0)  c++;
        }
        return c;
    }
};