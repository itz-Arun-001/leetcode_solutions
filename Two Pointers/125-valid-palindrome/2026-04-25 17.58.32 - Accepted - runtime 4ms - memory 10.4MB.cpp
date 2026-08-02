class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        vector<char> a;
        for(int i=0;i<n;i++)


        {
            if(s[i]>=65&&s[i]<91||s[i]>=97&&s[i]<123||s[i]>='0'&&s[i]<='9')
            {
                a.push_back(tolower(s[i]));
            }


        }
        int j=a.size();
        int l=0;
        int h=j-1;
        while(l<h)
        {
            if(a[l]!=a[h])  return false;
            else{
                    l++;h--;
            }
        }
        return true;
    }
};