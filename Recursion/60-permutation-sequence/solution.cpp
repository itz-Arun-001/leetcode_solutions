class Solution {
public:
    string getPermutation(int n, int k) {
        int f=1;
        vector<int>nums;
        for(int i=1;i<n;i++)
        {
            nums.push_back(i);
            f=f*i;
        }
        nums.push_back(n);
        string ans="";
        k-=1;
        while(true)
        {
            ans+=to_string(nums[k/f]);
            nums.erase(nums.begin()+k/f);
            if(nums.size()==0) break;
            k%=f;
            f=f/nums.size();
        }
        return ans;
    }
};
