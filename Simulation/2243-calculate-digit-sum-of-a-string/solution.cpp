class Solution {
public:
    string help(string temp)
    {
        int val=0;
        int k=temp.size();
        for(int i=0;i<k;i++)
        {
            val+=(temp[i]-'0');
        }
        return to_string(val);
    }
    string digitSum(string s, int k) {
        int n=s.size();
        while(n>k)
        {
            string temp="";
            for(int i=0;i<n;i+=k)
            {
                temp+=help(s.substr(i,k));
            }
            s=temp;
            n=s.size();
        }
        return s;
    }
};
