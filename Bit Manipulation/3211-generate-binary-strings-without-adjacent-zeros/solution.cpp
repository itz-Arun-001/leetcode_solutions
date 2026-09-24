class Solution {
public:
    vector<string>ans;
    void help(int &n,string& temp,int& prev,int & size)
    {
        if(size==n)
        {
            ans.push_back(temp);
            return;
        }
        if(prev!=0)
        {
            int x=prev;
            temp.push_back('0');
            prev=0;
            size++;
            help(n,temp,prev,size);
            temp.pop_back();
            prev=x;
            size--;
        }
        int x=prev;
            temp.push_back('1');
            prev=1;
            size++;
            help(n,temp,prev,size);
            temp.pop_back();
            prev=x;
            size--;

    }
    vector<string> validStrings(int n) {
        string temp="";
        int prev=-1;
        int s=0;
        help(n,temp,prev,s);
        return ans;
    }
};
