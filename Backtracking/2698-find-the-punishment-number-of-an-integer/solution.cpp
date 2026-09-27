class Solution {
public:
    bool pos(string s,int idx,int target,int sum)
    {
        if(idx==s.size())
        {
            return sum==target;
        }
        int num=0;
        for(int i= idx;i<s.size();i++)
        {
            num=num*10+(s[i]-'0');
            if(sum+num>target)
                break;
            if(pos(s,i+1,target,sum+num))
                return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int sqr=i*i;
            string s=to_string(sqr);
            if(pos(s,0,i,0))
                ans+=sqr;
        }
        return ans;
    }
};
