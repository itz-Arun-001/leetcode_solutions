class Solution {
public:
    vector<string>ans;
    void help(string &s,int idx,string& temp,int &n)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }
           temp.push_back(s[idx]);
        help(s, idx + 1, temp,n);
        temp.pop_back();
        if(isalpha(s[idx])) {
            if(s[idx] >= 'a' && s[idx] <= 'z')
                temp.push_back(s[idx] - 32);
            else
                temp.push_back(s[idx] + 32);
            help(s, idx + 1, temp,n);
            temp.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        string temp="";
        int n=s.size();
        help(s,0,temp,n);
        return ans;
    }
};
