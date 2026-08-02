class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        long long maxa=0;
       int mp[1000001]={0};
        
        int l=0;
        for(int r=0;r<n;r++)
        { mp[nums[r]]++;
            ans+=nums[r];
       while(mp[nums[r]]>1)
            {
                mp[nums[l]]--;
                ans-=nums[l];
              
                l++;
            }
           
            if(r-l+1==k)
            {
            maxa=max(maxa,ans);
            mp[nums[l]]--;
            ans-=nums[l++];
            }

            

        }
        return maxa;

        
    }
};
/*class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        long long maxa=0;
        unordered_map<int,int>mp;
        
        int l=0;
        for(int r=0;r<n;r++)
        { mp[nums[r]]++;
            ans+=nums[r];
            while(r-l+1>k)
            {
                mp[nums[l]]--;
                ans-=nums[l];
                if(mp[nums[l]]==0)    mp.erase(nums[l]);
                l++;
            }
           
            if(r-l+1==k&&mp.size()==k)
            {
            maxa=max(maxa,ans);
            }

            

        }
        return maxa;

        
    }
};
*/