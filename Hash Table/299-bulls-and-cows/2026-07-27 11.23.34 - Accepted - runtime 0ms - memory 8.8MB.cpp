class Solution {
public:
    string getHint(string s, string g) {
        //string s=to_string(secret);
        //string g=to_string(guess);
        int bcnt=0;
        int ccnt=0;
        vector<int>shelp(10,0);
        vector<int>ghelp(10,0);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==g[i])
            {
                bcnt++;
            }
            else{
            shelp[s[i]-'0']++;
            ghelp[g[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++)
        {
            ccnt+=min(shelp[i],ghelp[i]);
        }
        string ans = to_string(bcnt) + "A" + to_string(ccnt) + "B";
        return ans;

        
    }
};