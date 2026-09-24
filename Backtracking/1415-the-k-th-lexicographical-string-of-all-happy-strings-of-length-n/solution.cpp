class Solution {
public:
    string ans;
    void help(vector<char>& chars,int idx,string& curr,char &prev,int & n,int& k)
    {
        if(idx==n) 
        {
            k--;
            if(k==0)
            {
                ans=curr;
                
            }
            return;
        }
        for(int i=0;i<3;i++)
        {
            if(prev==chars[i])
            {
                continue;
            }
            curr.push_back(chars[i]);
            char temp=prev;
            prev=chars[i];
            help(chars,idx+1,curr,prev,n,k);
            curr.pop_back();
            prev=temp;
        }
    }
    string getHappyString(int n, int k) {
        vector<char> str={'a','b','c'};
        string curr="";
        char prev='*';
        help(str,0,curr,prev,n,k);
        return ans;

    }
};
