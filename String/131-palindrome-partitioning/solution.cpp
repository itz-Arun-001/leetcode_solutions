class Solution {
public:
    vector<vector<string>>ans;
    bool ispla(string s)
    {
        string a=s;
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            swap(s[i],s[n-i-1]);
        }
        return a==s;
    }
    void help(vector<string>& temp, string& s, int idx,int& size) {
        if (idx==size) {
            ans.push_back(temp);
            return;
        }
        for (int i=idx;i<size;i++) {
            string x =s.substr(idx,i-idx+1);
            if (ispla(x)) {
                temp.push_back(x);
                help(temp,s,i+1,size);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>temp;
        int n=s.size();
        help(temp,s,0,n);
        return ans;
    }
};
