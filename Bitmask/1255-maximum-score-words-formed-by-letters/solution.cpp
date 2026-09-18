class Solution {
public:
    bool ispossible(string s,vector<int>& freq )
    {
    vector<int> temp(26, 0);
    for(char c:s)
    {
       int x=c-'a';
        temp[x]++;
        if(temp[x]>freq[x])
            return false;
    }
    return true;
    }
    void help(vector<string>& words, vector<char>& letters, vector<int>& score,vector<int >& freq,int idx,int &mx,int &sum)
    {
        for (int i=idx;i <words.size();i++)
        {
            if(ispossible(words[i],freq))
            {
                int a= words[i].size();
                int temp=0;
                for(int j=0; j<a;j++)
                {
                    freq[words[i][j]-'a']--;
                temp+=score[words[i][j]-'a'];
                }
                sum+=temp;
                mx=max(sum,mx);
                help(words,letters,score,freq,i+1,mx,sum);
                for(int j=0; j<a;j++)
                {
                    freq[words[i][j]-'a']++;
                }
                sum-=temp;
                
                
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int mx=0; int s=0; 
        vector<int> freq(26,0);
        for(char c: letters)
            {
                freq[c-'a']++;
            }
        help( words,letters,score,freq,0,mx,s);
        return mx;
    }
};
