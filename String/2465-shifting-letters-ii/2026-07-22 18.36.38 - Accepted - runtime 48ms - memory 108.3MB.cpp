class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.size() + 1, 0);
        for (auto a : shifts) {
            int start = a[0];
            int end = a[1];
            int dir = a[2];
            if (dir == 1) {
                diff[start] += 1;
                diff[end + 1] -= 1;
            } else {
                diff[start] -= 1;
                diff[end + 1] += 1;
            }
        }
        for (int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
        }
        /* for(int i=0;i<s.size();i++)
         {
             int x=s[i]-'a';
             x+=diff[i];
             x%=26;
             x+='a';
             s[i]+=(char)x;
         }*/
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            x = (x + diff[i]) % 26;
            if (x < 0)
                x += 26;
            s[i] = x + 'a';
        }
        return s;
    }
};