class Solution {
public:
    string sortSentence(string s) {
        int n=s.size();
        vector<string>temp(10,"");
        string x="";int pos;
       for(int i=0;i<n;i++)
        {
            x="";
            while(i<n&&s[i]!=' ')
            {
                x+=s[i++];

            }
            pos=x.back()-'0';
           temp[pos-1]=x.substr(0,x.size()-1);
        }
        string res="";
        for(int i=0;i<10;i++)
        {
            if(temp[i]!="")
            {
                if(!res.empty())
                    res+=" ";
                res+=temp[i];
            }
            else break;
        }
        return res;
    }
};

            

/*
class Solution {
public:
    string sortSentence(string s) {
        int n=s.size();
        vector<pair<int,string>>temp;
        string x="";
        for(int i=0;i<n;i++)
        {
            x="";
            while(i<n&&s[i]!=' ')
            {
                x+=s[i++];

            }
            temp.push_back({(x[x.size()-1])-'0',x.substr(0,x.size()-1)});

        }
        sort(temp.begin(),temp.end());
        string ans="";
        n=temp.size();
        for(int i=0;i<n;i++)
        {
            auto p=temp[i];
            ans+=p.second;
            if(i!=n-1) ans+=" ";   
        }
        return ans;
        
    }
};

*/
