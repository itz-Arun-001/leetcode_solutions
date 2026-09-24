class Solution {
public:
    string ans = "";
    void help(string& pat, int idx, string& curr, int& prev,vector<bool>& visited, int& n) {
        if (!ans.empty())
            return;
        if (curr.size()==n+1) {
            ans=curr;
            return;
        }
        if (curr.empty()) {
            for (int i=1;i<=9;i++) {
                visited[i]=true;
                curr.push_back(i+'0');
                int temp=prev;
                prev=i;
                help(pat,0,curr,prev,visited,n);
                prev=temp;
                curr.pop_back();
                visited[i]=false;
            }
            return;
        }
        for(int i=1;i<= 9;i++) {
            if (visited[i])
                continue;
            if (pat[curr.size()-1]=='I'&&prev<i) {
                int temp=prev;
                prev=i;
                visited[i]=true;
                curr.push_back(i+'0');
                help(pat,idx+1,curr,prev,visited,n);
                curr.pop_back();
                visited[i]=false;
                prev=temp;
            }
            if(pat[curr.size()-1]=='D'&&prev>i) {
                int temp =prev;
                prev=i;
                visited[i]=true;
                curr.push_back(i+'0');
                help(pat,idx+1,curr,prev,visited,n);
                curr.pop_back();
                visited[i]=false;
                prev=temp;
            }
        }
    }
    string smallestNumber(string pattern) {
        vector<bool> vis(10, false);
        string cur = "";
        int prev =0;
        int n = pattern.size();
        help(pattern, 0, cur, prev, vis, n);
        return ans;
    }
};
