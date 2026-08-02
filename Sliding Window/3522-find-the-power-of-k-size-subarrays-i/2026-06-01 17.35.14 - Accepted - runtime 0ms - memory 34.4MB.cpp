class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        int a = 0;

        // Count bad adjacent pairs in first window
        for (int i = 0; i < k - 1; i++) {
            if (nums[i + 1] != nums[i] + 1)
                a++;
        }

        ans.push_back(a == 0 ? nums[k - 1] : -1);

        for (int l = 0, r = k; r < n; l++, r++) {
            // Remove adjacency (l, l+1)
            if (nums[l + 1] != nums[l] + 1)
                a--;

            // Add adjacency (r-1, r)
            if (nums[r] != nums[r - 1] + 1)
                a++;

            ans.push_back(a == 0 ? nums[r] : -1);
        }

        return ans;
    }
};
/*class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
      int n=numss.size();
        vector<int>ans;
        int a=0,p=0;
        for(int i=0;i<k-1;i++)
        {
            if(nums[i]==nums[i+1]-1)
            {p=max(p,nums[i];
            continue;}
            else{
                a=1;
                break;
            }
        }
        if(a==0)    ans.push_back(p);
        else    ans.push_back(-1);
        for(int i=k;i<n;i++)
        {
            p/=nums[i-1]
            if(nums[i]==nums[i+1]-1)
            {
                
            }
        }
        
    }
};*/