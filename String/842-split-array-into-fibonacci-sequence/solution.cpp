class Solution {
public:
    vector<int>ans;
    bool help(string nums,int idx,long long& prev1,long long& prev2,int& n)
    {
        if(idx==n)
        {
            if(ans.size()>=3) return true;
            return false;
        }
         long long val=0;
        for(int i=idx;i<n;i++)
        {
            if (nums[idx]=='0'&&i>idx)
                 break; 
            string temp=nums.substr(idx,i-idx+1);
            //long long val=stoll(temp);
           
            val=val*10+(nums[i]-'0');
            if (val>INT_MAX)
                break;
            if (ans.size() < 2)
            {
                ans.push_back(val);
                long long x1 = prev1;
                long long x2 = prev2;
                 if (ans.size() == 1)
                    prev1 = val;
                else
                    prev2 = val;
                if (help(nums, i + 1, prev1, prev2, n))
                    return true;
                prev1 = x1;
                prev2 = x2;
                ans.pop_back();
            }
            else{
            if(val==prev1+prev2)
            {
                long long x=prev1;
                prev1=prev2;
                prev2= val;
                ans.push_back(val);
                if(help(nums,i+1,prev1,prev2,n))
                    return true;
                prev2=prev1;
                prev1=x;
                ans.pop_back();
            }
        }
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string num) {
        long long prev1=0,prev2=0;
        int n=num.size();
        bool res=help(num,0,prev1,prev2,n);
        if(res) return ans;
        vector<int>temp;
        return temp;
    }
};
