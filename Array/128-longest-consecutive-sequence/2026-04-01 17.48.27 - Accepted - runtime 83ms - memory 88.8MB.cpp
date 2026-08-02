class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>s(nums.begin(),nums.end());
        int high=0;
        for(int num:s)
        {
            if(s.find(num-1)==s.end())
            {
                int current=num;
                int count=1;
                while(s.find(current+1)!=s.end())
                {
                    count++;
                    current++;
                }
                high=max(high,count);

            }
        }
        return high;

       
        return high;
    }
};