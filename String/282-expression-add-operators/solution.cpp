class Solution {
public:

    void help(string& num,int idx,long long curr,long long prev,long long target,string expr, vector<string>& ans) {
        if(idx==num.size()) {
            if(curr==target) {
                ans.push_back(expr);
            }
            return;
        }
        for (int i=idx;i<num.size();i++) {
            if (num[idx]=='0'&&i>idx)
                 break;
            string part=num.substr(idx,i-idx+1);
            long long value = stoll(part);
            if (idx==0) {
                help(num,i+1,value,value,target,part,ans);
        }
            else {
                help(num,i+1,curr+value,value,target,expr+"+" +part,ans);
                help(num,i+1,curr-value,-value,target,expr+ "-"+ part,ans);
                help(num,i+1,curr-prev+prev*value,prev*value,target,expr + "*" + part,ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        help(num,0,0,0,target,"",ans);
        return ans;
    }
};
