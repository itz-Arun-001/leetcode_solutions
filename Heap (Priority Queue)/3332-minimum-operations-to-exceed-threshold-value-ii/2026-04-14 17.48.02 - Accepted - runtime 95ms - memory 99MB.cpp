class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int fmin=INT_MAX,smin=INT_MAX;
        int op=0;
        int n=nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }

        while(pq.top()<k&&pq.size()>=2)
        {
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            pq.push(a * 2 +b);
            op++;
        }
        if(pq.size()==1&&pq.top()<k)   return -1;
        return op;
        
    }
};