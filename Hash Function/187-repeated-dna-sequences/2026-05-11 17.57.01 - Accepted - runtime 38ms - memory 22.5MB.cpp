class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string>seen;
        unordered_set<string>rep;
//        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<=n-10;i++)

        {
            string a=s.substr(i,10);
            if(seen.count(a))
            {
                rep.insert(a);
            }
            else{
                seen.insert(a);
            }
        }   vector<string>ans(rep.begin(),rep.end());   
        return ans;

    }
  

};