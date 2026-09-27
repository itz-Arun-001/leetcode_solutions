class Solution {
public:
    vector<string>ans;
    void help(string &curr,int & cost,int &prev,int &n,int& k,int& size)
    {
        if(size==n)
        {
            if(cost<=k) ans.push_back(curr);
            return;
        }
        if(cost>k) return;
        if(prev!=1)
        {
            int t=prev;
            curr.push_back('1');
            prev=1;
            cost+=size;
            size++;
            help(curr,cost,prev,n,k,size);
            size--;
            cost-=size;
            prev=t;
            curr.pop_back();

        }
        int t=prev;
        curr.push_back('0');
        prev=0;
        size++;
        help(curr,cost,prev,n,k,size);
        size--;
        prev=t;
        curr.pop_back();
    }
    vector<string> generateValidStrings(int n, int k) {
        string curr="";
        int s=0;
        int c=0;
        int prev=-1;
        help(curr,c,prev,n,k,s);
        return ans;
    }
};
