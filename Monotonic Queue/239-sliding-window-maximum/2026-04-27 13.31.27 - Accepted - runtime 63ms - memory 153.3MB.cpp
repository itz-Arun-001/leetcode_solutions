class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /* vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>track;
         int n=nums.size();
         int l=0;
         for(int i=0;i<k;i++)
         {
             track.push(nums[i]);
             //a=max(a,nums[i]);
         }
         ans.push_back(track.back());
         for(int r=k;r<n;r++)
         {
             track.push(nums[r]);
             if(!track.empty()&&r-l+1>k)
             {
                 track.pop();
                 l++;
             }
             ans.push_back(track.back());
         }
         return ans;*/
        int n = nums.size();

        vector<int> ans;
        priority_queue<pair<int, int>>q;
        for (int i = 0; i < k; i++) {
            q.push({nums[i], i});
        }
        ans.push_back(q.top().first);
        for (int r = k; r < n; r++) {
            q.push({nums[r], r});
            while (q.top().second <= r - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }

        return ans;
    }
};