/*class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0, maxFreq = 0, ans = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>fre(26,0);
        int l=0,maxfre=0,ans=0,r=0;
        for(int i=0;i<n;i++)

        {
            fre[s[r]-'A']++;
            maxfre=max(maxfre,fre[s[r]-'A']);
            while((r-l+1)-maxfre>k)
            {
                fre[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};