/*class Solution {
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
};*/
class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<int,26>lower;
        array<int,26>higher;
        lower.fill(-1);
        higher.fill(-1);
        int n=word.size(),c=0;
        for(int i=0;i<n;i++)

        {
            if(word[i]>=65&&word[i]<=90)
            {
                if(higher[word[i]-'A']==-1)
                    higher[word[i]-'A']=i;
                
            }
            else{
                lower[word[i]-'a']=i;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(lower[i]==-1||higher[i]==-1) continue;
            else{
                if(higher[i]>lower[i])  c++;
            }
        }
        return c;
    }
};