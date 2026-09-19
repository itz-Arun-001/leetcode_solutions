class Solution {
public:
    unordered_set<string>st;
    int ans=0;
    void help(string& s,int idx,int & cnt,int &n)
    {
        if (idx ==n) {
            ans = max(ans, cnt);
            return;
        }
        for(int i=idx;i<n;i++)
        {
           string temp =s.substr(idx,i-idx+1);
            if(st.count(temp)==0)
            {
                st.insert(temp);
                cnt++;
                help(s,i+1,cnt,n);
                st.erase(temp);
                cnt--;
            }
        }

    }
    int maxUniqueSplit(string s) {
        int n=s.size();
        int cnt=0;
        help(s,0,cnt,n);
        return ans;
    }
};
