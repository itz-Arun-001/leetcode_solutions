/*class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                pos.push_back(nums[i]);
            else    neg.push_back(nums[i]);
        }
        nums.clear();
        int a=0,j=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                nums.push_back(pos[a++]);
            else    nums.push_back(neg[j++]);

        }
        return nums;
        
    }
};*/
//optimised format
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0,neg=1;
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                ans[pos]=nums[i];
                pos+=2;

            }
            else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};
