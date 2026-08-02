/*class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int rev=0;
             if(nums[i] == 0)
                continue;
            while(nums[i]>0)
            {
                 rev*=10;
                rev+=nums[i]%10;
               
                nums[i]/=10;

            }
            nums[i]=rev;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
             if(nums[i] == 0){
                ans.push_back(0);
                 continue;
               }
            while(nums[i]>0)
            {
                int a=nums[i]%10;
                nums[i]/=10;
                ans.push_back(a);
            }

        }
        return ans;
        
    }
};*/
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            string s=to_string(nums[i]);
            int a=s.size();
            for(int j=0;j<a;j++)
            {
                ans.push_back(s[j]-'0');
            }
        }
        return ans;
    }
};