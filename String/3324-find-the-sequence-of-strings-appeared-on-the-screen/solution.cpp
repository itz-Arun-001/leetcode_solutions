class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string temp="";
        for (char c:target) {
            for (char t='a';t<=c;t++) {
                ans.push_back(temp+t);
            }
            temp+=c;
        }
        return ans;
    }
};


/*class Solution {
public:
    void add(vector<string>&ans,char c,string temp)
    {
        temp+=c;
        ans.push_back(temp);
    }
    vector<string> stringSequence(string target) {
        vector<string>ans;
        string temp="";
        if(target=="") return ans;
        int n=target.size();
        for(int i=0;i<n;i++)
        {
            char c=target[i];
            char t='a';
            while(t<=c)
            {
                add(ans,t,temp);
                t++;
            }
            temp+=c;
        }
        return ans;
    }
};*/
