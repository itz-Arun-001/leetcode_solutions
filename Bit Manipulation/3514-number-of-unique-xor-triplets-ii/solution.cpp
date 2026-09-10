/*class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int>arr;
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr.push_back(nums[i]^nums[j]);
            }
        }
        int x=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<x;j++)
            {
                st.insert(nums[i]^arr[j]);
            }
        }
        return st.size();
        
    }
};*/
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool>arr(2048,false);
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
              arr[nums[i]^nums[j]]=true;
            }
        }
        int cnt=0;
        vector<bool>help(2048,false);
        for(int i=0;i<2048;i++)
        {
            if(arr[i]==false) continue;
            for(int j=0;j<n;j++)
            {
                int x=nums[j]^i;
                if(help[x]==false)
                {
                    help[x]=true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
