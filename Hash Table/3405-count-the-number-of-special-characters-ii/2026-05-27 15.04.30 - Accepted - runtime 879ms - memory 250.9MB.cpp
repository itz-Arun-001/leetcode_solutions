class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<set<int>,26>lower={};
        array<set<int>,26>high={};
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(word[i]>=65&&word[i]<=90)
            {
                high[word[i]-'A'].insert(i);
            }
            else
            {
                lower[word[i]-'a'].insert(i);
            }

        }
        int c=0;
        for(int i=0;i<26;i++)
        {
            if(high[i].empty()||lower[i].empty())  continue;
            if(*high[i].begin()>*lower[i].rbegin())
                c++;
        }
        return c;

    }
};