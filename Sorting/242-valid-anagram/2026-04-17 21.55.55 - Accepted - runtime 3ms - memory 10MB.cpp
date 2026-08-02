/*class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)
            return true;
        return false;
    }
};*/
class Solution {
public:
    bool isAnagram(string s, string t) { 
        unordered_map<char,int >m1,m2;
        int a=s.size();
        int b=t.size();
        for(int i=0;i<a;i++)
        {
            m1[s[i]]++;
        }
        for(int i=0;i<b;i++)
        {
            m2[t[i]]++;
        }
        if(m1==m2)  return true;
        return false;
    }
};